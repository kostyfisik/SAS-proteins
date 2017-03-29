#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
//using std::vector;
//using std::cin;
//using std::cout;
//using std::endl;
using namespace std;
const int SIZE = 2;

class SAScore
{
private:

	vector <int***> r_grid;
	vector< vector<int> > surface = vector< vector<int> >( 0, vector < int > (4));
	int elt;
	void GriddingMolecule(double r, double step);
	static bool sort_by_value(const vector <int>& vec1, const vector <int>& vec2);
	static bool sort_by_coord(const vector <int>& vec1, const vector <int>& vec2);

//	void GriddingTotal();
public:
	SAScore(double r, double step);//test
	SAScore(double data[SIZE][4], double r, double step);
	void PRINT();
	~SAScore();
};

