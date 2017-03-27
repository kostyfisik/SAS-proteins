#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;


class SAScore
{
private:
	vector<int***> r_grid;
	int elt;
	void Gridding (double r, double step);
	void Dehydrating ();
public:
	SAScore(double r, double step);
	SAScore(double data[200][4], double r, double step);
	void PRINT();
	~SAScore();
};

