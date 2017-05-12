#pragma once
#ifndef SAScore_H_
#define SAScore_H_
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

template <int dim = 3> class SAScore
{
private:
	
	//variables
	const double step_;
	enum struct State {
		kEmpty = 0,
		kFilled = 1,
		kBoundary = 2,
	};
	struct MoleculeTemplate {
		double r;
		std::vector< std::vector<int> > grid_molecule_ = std::vector< std::vector<int> >(0, std::vector < int >(dim + 1));
	};
	std::vector <MoleculeTemplate> molecule_templates_ = std::vector <MoleculeTemplate>(0);
	std::vector< std::vector<int> > hydrated_surface_ = std::vector< std::vector<int> >(0, std::vector < int >(dim + 1));
	std::vector< std::vector<int> > molecular_surface_ = std::vector< std::vector<int> >(0, std::vector < int >(dim + 1));
	MoleculeTemplate* existing_molecule_template_;

	//functions
	static bool SortByValue_(const std::vector <int>& vec1, const std::vector <int>& vec2);
	static bool InvSortByValue_(const std::vector <int>& vec1, const std::vector <int>& vec2);
	static bool SortByCoordXYZState_(const std::vector <int>& vec1, const std::vector <int>& vec2);
	static bool SortByCoordXYZ_(const std::vector <int>& vec1, const std::vector <int>& vec2);
	static bool SortByCoordYZX_(const std::vector <int>& vec1, const std::vector <int>& vec2);
	static bool SortByCoordZXY_(const std::vector <int>& vec1, const std::vector <int>& vec2);
	bool CoordCompare_(const std::vector<int>& a, const std::vector<int>& b);
	bool RadiusCheck_(const double& r);
	void MoleculeGridding_(const double& r);
	void DeleteEqualCoord_(std::vector< std::vector<int> >& data);
	void NewSpaceBuilder_(const std::vector<double>& data, MoleculeTemplate& molecule);
	void HydratedSurfaceBuilder_(const std::vector< std::vector<double> >& data);
	void MolecularSurfaceBuilder_(std::vector< std::vector<int> >& data);
	void SolventTemplateApply_(const std::vector<int>& data);
	void SaveUniqCoord_(std::vector< std::vector<int> >& data);
	bool CheckBoundaryState_(const std::vector<int>& cube1, const std::vector<int>& cube2);
	void MolecularBoundaryBuilder_();
public:
	SAScore(std::vector< std::vector<double> >& data, const double& r, const double& step);
	~SAScore();
};

//sorting by coordinates in XYZ
template <int dim>
bool SAScore<dim>::SortByCoordXYZ_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	for (int i = 0; i < dim; ++i) {
		if (vec1[i] == vec2[i]) continue;
		return vec1[i] < vec2[i];
	}
	return vec1[dim-1] < vec2[dim-1];///
}

//sorting by coordinates in YZX
template <int dim>
bool SAScore<dim>::SortByCoordYZX_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	for (int i = 1; i < dim; ++i) {
		if (vec1[i] == vec2[i]) continue;
		return vec1[i] < vec2[i];
	}
	return vec1[0] < vec2[0];
}

//sorting by coordinates in ZXY
template <int dim>
bool SAScore<dim>::SortByCoordZXY_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	for (int i = dim - 1; i >0; i -= 2) {
		if (vec1[i] == vec2[i]) continue;
		return vec1[i] < vec2[i];
	}
	return vec1[1] < vec2[1];
}

//sorting by coordinates in XYZ and state
template <int dim>
bool SAScore<dim>::SortByCoordXYZState_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	for (int i = 0; i <= dim; ++i) {
		if (vec1[i] == vec2[i]) continue;
		return vec1[i] < vec2[i];
	}
	return vec1[dim] < vec2[dim];
}

//sorting by value and coordinates
template <int dim>
bool SAScore<dim>::SortByValue_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	if (vec1[dim] < vec2[dim])
	for (int i = 0; i < dim; ++i) {
		if (vec1[i] == vec2[i]) continue;
		return vec1[i] < vec2[i];
	}
	return vec1[dim] < vec2[dim];
}

//inversed sorting only by value
template <int dim>
bool SAScore<dim>::InvSortByValue_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	return vec1[dim] > vec2[dim];
}

//comparing of coordinates
template <int dim>
bool SAScore<dim>::CoordCompare_(const std::vector<int>& a, const std::vector<int>& b) {
	for (int i = 0; i < dim; ++i) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

//checking existing template
template <int dim>
bool SAScore<dim>::RadiusCheck_(const double& r) {
	for (int i=0; i< molecule_templates_.size(); ++i)
		if (r == molecule_templates_[i].r) {
			existing_molecule_template_ = &molecule_templates_[i]; //should be checked
			return true;
		}
	return false;
}

//Gridding of a molecule
template <int dim>
void SAScore<dim>::MoleculeGridding_(const double& r) {
	int r_int = round(r / step_);
	int x[3] = { 0 };
	double r_sq = pow(r, 2), check_point_sq = 0, r_int_sq = pow((r_int-1)*step_, 2);
	MoleculeTemplate molecule_template;
	molecule_template.r = r;
	std::vector <int> new_coord(dim + 1, 0);
	for (x[0]=0; x[0] < 2 * r_int + 1; ++x[0]) {
		for (x[1]=0; x[1] < 2 * r_int + 1; ++x[1]) {
			for (x[2]=0; x[2] <(2 * r_int)*(dim - 2) + 1; ++x[2]) {
				//creating new coordinates and calculating cube distance from the centre of sphere
				for (int i = 0; i < dim; ++i) {
					new_coord[i] = x[i] - r_int;
					check_point_sq += pow(new_coord[i] * step_, 2);
				}
				//defining status of of cube
				if (r_int_sq < check_point_sq && check_point_sq <= r_sq) {//problem, big problem
					new_coord[dim] = int(State::kBoundary);
					molecule_template.grid_molecule_.push_back(new_coord);
				}
				else if (check_point_sq < r_sq) {
					new_coord[dim] = int(State::kFilled);
					molecule_template.grid_molecule_.push_back(new_coord);
				}
				check_point_sq = 0;
			}
		}
	}
	molecule_templates_.push_back(molecule_template);
}

//building new space
template <int dim>
void SAScore<dim>::NewSpaceBuilder_(const std::vector<double>& data, MoleculeTemplate& molecule) {
		
	std::vector <int> centre_coord(dim, 0);
	std::vector <int> new_coord(dim + 1, 0);
	for (int i = 0; i < dim; ++i) {
		centre_coord[i] = round(data[i] / step_);
	}
	for (auto i : molecule.grid_molecule_) {
		for (int j = 0; j < dim; ++j) {
			new_coord[j] = centre_coord[j] + i[j];
		}
		new_coord[dim] = i[dim];
		hydrated_surface_.push_back(new_coord);
	}

}

//Deleting equal coordinate(s) 
template <int dim>
void SAScore<dim>::DeleteEqualCoord_(std::vector< std::vector<int> >& data) {
	std::vector< std::vector<int> > temp (0);
	if (!CoordCompare_(data[0], data[1])) temp.push_back(data[0]);
	for (int i = 1; i < data.size(); ++i) {
		if (!CoordCompare_(data[i - 1], data[i]))
			temp.push_back(data[i]);
	}
	data = temp;
}

//Saving only equal coordinate(s) with state equal to kFilled(1)
template <int dim>
void SAScore<dim>::SaveUniqCoord_(std::vector< std::vector<int> >& data) {
	int l = data.size() - 1;
	std::vector < std::vector<int> > temp(0);
	if (!CoordCompare_(data[0], data[1])) {
		if (data[0][dim] == 1) {
			temp.push_back(data[0]);
		}
	}
	for (int i = 1; i < l - 1; i += 2) {
		if (!CoordCompare_(data[i], data[i + 1]) && !CoordCompare_(data[i], data[i - 1])) {
			if (data[i][dim] == 1) {
				temp.push_back(data[i]);
			}
		}
	}
	if (!CoordCompare_(data[l - 1], data[l])) {
		if (data[l][dim] == 1) {
			temp.push_back(data[l]);
		}
	}
	data = temp;
}

//bulding of hydrated surface
template <int dim>
void SAScore<dim>::HydratedSurfaceBuilder_(const std::vector< std::vector<double> >& data) {
	for (auto i : data) {
		if (!RadiusCheck_(i[dim])) {
			MoleculeGridding_(i[dim]);
			NewSpaceBuilder_(i, molecule_templates_.back());
		}
		else {
			NewSpaceBuilder_(i, *existing_molecule_template_);
		}
	}

	sort(hydrated_surface_.begin(), hydrated_surface_.end(), SortByCoordXYZState_);
	DeleteEqualCoord_(hydrated_surface_);
}

//applying solvent template on the boundary 
template <int dim>
void SAScore<dim>::SolventTemplateApply_(const std::vector<int>& data) {
	std::vector <int> cube(dim + 1);
	for (auto i : molecule_templates_[0].grid_molecule_) {
		for (int j = 0; j < dim; ++j) {
			cube[j] = data[j] + i[j];
		}
		cube[dim] = int(State::kEmpty);
		molecular_surface_.push_back(cube);
	}
}

//Check boundary of molecular surface
template <int dim>
bool SAScore<dim>::CheckBoundaryState_(const std::vector<int>& cube1, const std::vector<int>& cube2) {
	int d = 0;
	for (int i = 0; i < dim; ++i) {
		d += abs(cube1[i] - cube2[i]);
	}
	if (d > 1) return true;
	else return false;
}

//building of molecular boundary
template <int dim>
void SAScore<dim>::MolecularBoundaryBuilder_() {
	for (int i = 0; i< molecular_surface_.size()-1; ++i) {
		if (CheckBoundaryState_(molecular_surface_[i], molecular_surface_[i + 1]))
			molecular_surface_[i][dim] = molecular_surface_[i + 1][dim] = int(State::kBoundary);
	}
}

//building of molecular surface
template <int dim>
void SAScore<dim>::MolecularSurfaceBuilder_(std::vector< std::vector<int> >& data) {
	molecular_surface_ = hydrated_surface_;
	sort(hydrated_surface_.begin(), hydrated_surface_.end(), InvSortByValue_);
	for (auto i : data){
		if (i[dim] != int(State::kBoundary)) break;
		SolventTemplateApply_(i);
	}
	sort(molecular_surface_.begin(), molecular_surface_.end(), SortByCoordXYZ_);
	//qsort(molecular_surface_, molecular_surface_.size(),sizeof(std::vector<int>), compare);

	//sort(molecular_surface_.begin(), molecular_surface_.end(), SortByCoordXYZ_);
	//SaveUniqCoord_(molecular_surface_);
	/*MolecularBoundaryBuilder_();
	sort(molecular_surface_.begin(), molecular_surface_.end(), SortByCoordYZX_);
	MolecularBoundaryBuilder_();
	sort(molecular_surface_.begin(), molecular_surface_.end(), SortByCoordZXY_);
	MolecularBoundaryBuilder_();*/
}

//constructor
template <int dim>
SAScore<dim>::SAScore(std::vector< std::vector<double> >& data, const double& r, const double& step) :step_(step)
{
	std::cout << "Gridding a molecule of solvent" << std::endl;
	MoleculeGridding_(r);
	std::cout << "Finished!!!" << std::endl;
	std::cout << "Gridding molecules of the protein and building of hydrated surface" << std::endl;
	HydratedSurfaceBuilder_(data);
	std::cout << "Finished!!!" << std::endl;
	std::cout << "Building of molecular surface" << std::endl;
	MolecularSurfaceBuilder_(hydrated_surface_);
	std::cout << "Finished!!!" << std::endl;

        
        /* std::sort(molecular_surface_.begin(), molecular_surface_.end(), SortByValue_); */
        std::sort(molecular_surface_.begin(), molecular_surface_.end(),
                  [](const std::vector<int>& vec1, const std::vector<int>& vec2){
                    for(size_t i = 0; i < vec1.size() && i < vec2.size(); ++i){
                      if(vec1[i] > vec2[i]) return true;
                      if(vec1[i] < vec2[i]) return false;
                    }
                    return true;
                  }
                  );
	
        for (auto elem : molecular_surface_) {
          for (auto  i : elem) std::cout<< i << " ";
          std::cout<< std::endl;
        }
	std::cout << "Writting in  file" << std::endl;
	std::ofstream myfile;
	myfile.open("example.txt");
	for (auto i : /*molecule_templates_[0].grid_molecule_*/molecular_surface_) {
		//if (i[dim] == 0) {
			for (int j = 0; j <= dim; ++j) {
				myfile << i[j] << ' ';
			}
			myfile << std::endl;
	//	}
	}

	myfile.close();
	std::cout << "Finished!!!" << std::endl;
}

//destructor
template <int dim>
SAScore<dim>::~SAScore()
{
}

#endif 
