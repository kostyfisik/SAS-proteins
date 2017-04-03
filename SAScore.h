#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <int dim = 3> class SAScore
{
private:
	std::vector< std::vector<int> > surface_ = std::vector< std::vector<int> >(0, std::vector < int > (4));
	struct grid_molecule_ {
		double r;
		std::vector< std::vector<int> > r_grid_ = std::vector< std::vector<int> >(0, std::vector < int >(dim+1));
	} ;

	std::vector <grid_molecule_> molecule_templates_ = std::vector <grid_molecule_>(0);

	void GriddingMolecule_(const double r, const double step);
	static bool SortByValue_(const std::vector <int>& vec1, const std::vector <int>& vec2);
	static bool SortByCoord_(const std::vector <int>& vec1, const std::vector <int>& vec2);
public:
	 SAScore(std::vector< std::vector<int> > data, const double r, const double step);
	 ~SAScore();
};

template < int dim>
bool SAScore<dim>::SortByValue_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	return vec1[dim] < vec2[dim];
}

template < int dim>
bool SAScore<dim>::SortByCoord_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	if (vec1[0] == vec2[0]) {
		if (vec1[1] == vec2[1]) {
			return vec1[2] < vec2[2];
		}
		else return vec1[1] < vec2[1];
	}
	else
		return vec1[0] < vec2[0];
}

template <int dim>
void SAScore<dim>::GriddingMolecule_(const double r, const double step) {
	int h = round(r / step);
	int x[3];
	for (int i = 0; i < 3; ++i)
		x[i] = 0;
	double r_sq = pow(r, 2), check_r_sq = 0, check_step_sq = pow(step,2)/2;
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
					check_r_sq += pow(coord[i] * step, 2);
				}
				if (check_r_sq <= r_sq && r_sq < pow(sqrt(check_r_sq)+step/sqrt(2),2)){ //Should be modifieded
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
SAScore<dim>::SAScore(std::vector< std::vector<int> > data, const double r, const double step)
{
	//std::cout << "Initializing of arrays" << std::endl;
	//std::cout << "Gridding of solvent " << std::endl;
	GriddingMolecule_(r, step);
	GriddingMolecule_(data[0][3], step);

}

template <int dim>
SAScore<dim>::~SAScore()
{
}
