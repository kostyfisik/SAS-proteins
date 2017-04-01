#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <const int dim> class SAScore
{
private:

	std::vector< std::vector<int> > r_grid_ = std::vector< std::vector<int> >(0, std::vector < int >(4));
	std::vector< std::vector<int> > surface = std::vector< std::vector<int> >(0, std::vector < int > (4));
	void GriddingMolecule_(const double r, const double step);
	static bool SortByValue_(const std::vector <int>& vec1, const std::vector <int>& vec2);
	static bool SortByCoord_(const std::vector <int>& vec1, const std::vector <int>& vec2);
public:
	 SAScore(std::vector< std::vector<int> >& data, const double r, const double step);
	 ~SAScore();
};

