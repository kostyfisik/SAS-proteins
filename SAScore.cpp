#include "SAScore.h"

template <const int dim>
bool SAScore::SortByValue_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	return vec1[dim] < vec2[dim];
}

template <const int dim>
bool SAScore::SortByCoord_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	if (vec1[0] == vec2[0]) {
		if (vec1[1] == vec2[1]) {
			return vec1[2] < vec2[2];
		}
		else return vec1[1] < vec2[1];
		}
	else
		return vec1[0] < vec2[0];
}

template <const int dim>
void SAScore::GriddingMolecule_(const double r, const double step) {
	int h = round(r / step);
	double r_sq = pow(r, 2), check_r=0;
	std::vector <int> coord(4);
	for (int x = 0; x < 2 * h + 1; x++) {
		for (int y = 0; y < 2 * h + 1; y++) {
			for (int z = 0; z < 2 * h + 1; z++) {
				coord[0] = x - h;
				coord[1] = y - h;
				coord[2] = z - h;
				for (int i = 0; i < 3; i++) {
					check_r += pow(coord[i] * step, 2);
				}
				check_r = sqrt(check_r);
				if ((r - check_r) >= 0 && (r - check_r) <=step / sqrt(2))
					coord[3] = 2;
				else if (check_r < r)
					coord[3] = 1;

				surface.push_back(coord);
			}
		}
	}
	for (int x = 0; x < surface.size(); x++) {
		for (int i = 0; i < 4; i++) {
			std::cout << surface[x][i] << ' ';
		}
		std::cout << std::endl;
	}

}

template <const int dim>
SAScore::SAScore(std::vector< std::vector<int> >& data, const double r, const double step)
{
	//std::cout << "Initializing of arrays" << std::endl;
	//std::cout << "Gridding of solvent " << std::endl;
	GriddingMolecule_(r, step);

}

template <const int dim> 
SAScore::~SAScore()
{
}
