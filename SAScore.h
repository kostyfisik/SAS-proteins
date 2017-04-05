#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <int dim = 3> class SAScore
{
private:
	
	const double step_;
	std::vector< std::vector<int> > surface_ = std::vector< std::vector<int> >(0, std::vector < int > (4));
	std::vector< std::vector<int> > molecule_surface_ = std::vector< std::vector<int> >(0, std::vector < int >(4));
	std::vector< std::vector<int> > solvent_surface_ = std::vector< std::vector<int> >(0, std::vector < int >(3));
	struct grid_molecule_ {
		double r;
		std::vector< std::vector<int> > r_grid_ = std::vector< std::vector<int> >(0, std::vector < int >(dim+1));
	} ;
	
	std::vector <grid_molecule_> molecule_templates_ = std::vector <grid_molecule_>(0);
	grid_molecule_ exist_molecule_template_;

	bool CoordCompare_(std::vector<int>& a, std::vector<int>& b);
	bool RadiusCheck_(const double r);
	void GriddingMolecule_(const double r);
	void SurfaceBuilder_(const std::vector <double>& data, grid_molecule_& molecule);
	void SolventSurfaceBuilder_(const std::vector <int>& data);
	static bool SortByValue_(const std::vector <int>& vec1, const std::vector <int>& vec2);
	static bool SortByCoord_(const std::vector <int>& vec1, const std::vector <int>& vec2);
	void DeleteEqualCoord_();
	void SolventSurfaceBuilder_(std::vector<int> &data);
	void TotalSolventSurfaceBuilder_();

public:
	 SAScore(std::vector< std::vector<double> > data, const double r, const double step);
	 ~SAScore();
};



template <int dim>
bool SAScore<dim>::CoordCompare_(std::vector<int>& a, std::vector<int>& b) {
	for (int i = 0; i < dim; ++i) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

template <int dim>
void SAScore<dim>::DeleteEqualCoord_() {
	int j = 1;
	for (int i = 0; i < surface_.size() - 1; ++i) {
		j = i+1;
		while (CoordCompare_(surface_[i], surface_[j]) && j < surface_.size()) {
			surface_.erase(surface_.begin() + j);
			++j;
		}	
	}
}
template <int dim>
void SAScore<dim>::SolventSurfaceBuilder_(std::vector<int> &data) {
	std::vector <int> coord(dim);
	for (auto i : molecule_templates_[0].r_grid_) {
		for (int j=0; j < dim; ++j) {
			coord[j] = data[j] + i[j];
		}
		solvent_surface_.push_back(coord);
	}
}

template <int dim>
void SAScore<dim>::TotalSolventSurfaceBuilder_() {
	int i = 0;
	while (surface_[i][dim] != 2){
		++i;
	}
	int a = i;
	for (i; i < surface_.size(); ++i) {
		SolventSurfaceBuilder_(surface_[i]);
	}
	for (int j = 0; j < solvent_surface_.size(); ++j) {
		for (i = 0; i < a; ++i) {
			if (CoordCompare_(surface_[i], solvent_surface_[j])) {
				molecule_surface_.erase(molecule_surface_.begin() + i);
				--a;
				break;
			}
		}
	}
}

template <int dim>
void SAScore<dim>::SurfaceBuilder_(const std::vector <double>& data, grid_molecule_ & molecule) {
	std::vector <int> centre_coord(dim,0);
	std::vector <int> new_coord(dim+1,0);
	for (int i = 0; i < dim; ++i) {
		centre_coord[i] = round(data[i] / step_);
	}
	for (auto i : molecule.r_grid_) {
		for (int j = 0; j < dim; ++j){
			new_coord[j] = centre_coord[j] + i[j];
	}
		new_coord[dim] = i[dim];
		surface_.push_back(new_coord);
	}
}

template <int dim>
bool SAScore<dim>::RadiusCheck_(const double r) {
	for (auto i : molecule_templates_)
		if (r == i.r){
			exist_molecule_template_ = i;
			return true;
		}
	return false;
}

template <int dim>
bool SAScore<dim>::SortByValue_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	return vec1[dim] < vec2[dim];
}

template <int dim>
bool SAScore<dim>::SortByCoord_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	if (vec1[0] == vec2[0]) {
		if (vec1[1] == vec2[1]) {
			if (vec1[2] == vec2[2]) {
				return vec1[3] < vec2[3];
			}
			else return vec1[2] < vec2[2];
		}
		else return vec1[1] < vec2[1];
	}
	else
		return vec1[0] < vec2[0];
}

template <int dim>
void SAScore<dim>::GriddingMolecule_(const double r) {
	int h = round(r / step_);
	int x[3];
	for (int i = 0; i < 3; ++i)
		x[i] = 0;
	double r_sq = pow(r, 2), check_r_sq = 0, check_step_sq = pow(step_,2)/2;
	grid_molecule_ molecule_template;
	molecule_template.r = r;
 	std::vector <int> coord(dim+1,0);
	for (x[0] = 0; x[0] < 2 * h + 1; ++x[0]) {
		for (x[1] = 0; x[1] < 2 * h + 1; ++x[1]) {
			for (x[2] = 0; x[2] <( 2 * h)*(dim-2) + 1; ++x[2]) {
				for (int i = 0; i < dim; ++i) {
					coord[i] = x[i] - h;
				}
				for (int i = 0; i < dim; i++) {
					check_r_sq += pow(coord[i] * step_, 2);
				}
				if (check_r_sq <= r_sq && r_sq < pow(sqrt(check_r_sq)+step_/sqrt(2),2)){ //Should be modifieded
					coord[dim] = 2;
					molecule_template.r_grid_.push_back(coord);
				}
				else if (check_r_sq < r_sq) {
					coord[dim] = 1;
					molecule_template.r_grid_.push_back(coord);
				}
				check_r_sq = 0;
		}
		}
	}
	molecule_templates_.push_back(molecule_template);
}

template <int dim>
SAScore<dim>::SAScore(std::vector< std::vector<double> > data, const double r, const double step):step_(step)
{
	std::cout << "Gridding a molecule of solvent" << std::endl;
	GriddingMolecule_(r);
	std::cout << "Gridding molecules of the protein" << std::endl;
	for (auto i : data) {
		if (!RadiusCheck_(i[dim])) {
			GriddingMolecule_(i[dim]);
			SurfaceBuilder_(i, molecule_templates_.back());
		}
		else {
			SurfaceBuilder_(i, exist_molecule_template_);
		}
	}
	sort(surface_.begin(), surface_.end(), SortByCoord_);
	DeleteEqualCoord_();
	sort(surface_.begin(), surface_.end(), SortByValue_);
	molecule_surface_ = surface_;
	TotalSolventSurfaceBuilder_();
}

template <int dim>
SAScore<dim>::~SAScore()
{
}
