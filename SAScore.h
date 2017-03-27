#pragma once
#include <iostream>
#include <cstdio>
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
//	void GriddingTotal();
public:
	SAScore(double r, double step);//test
	SAScore(double data[SIZE][4], double r, double step);
	void PRINT();
	~SAScore();
};

