#include <iostream>
#include <vector>
#include <cmath>
#include "SAScore.h"

void main() {
	SAScore b(5,0.001);
	//b.PRINT();
	system("pause");
	/*double step = 0.5;
	double r = 5;
	int h = round(r / step), sh=1;
	int elt = 2 * (h + sh+1)-1;
	int ***mat = new int**[elt];
	for (int i = 0; i <elt; i++)
		mat[i] = new int*[elt];
	for (int i = 0; i < elt; i++)
		for (int j = 0; j < elt; j++)
			mat[i][j] = new int[elt];

	double d = 0;
	/*for (int x = 0; x < elt; x++ )
	//int x = 11;
		for (int y = 0; y <  elt; y++) 
			for (int z = 0; z < elt; z++) {
				d = sqrt(pow(( h+sh - x), 2) + pow((h + sh - y), 2) + pow((h + sh - z), 2))*step;
				if (abs(d-r) <  step/sqrt(2))
					mat[x][y][z] = 2;
				else if (d < r)
					mat[x][y][z] = 1;
				else if (d > r)
					mat[x][y][z] = 0;
		
for (int x = 0; x <= elt / 2; x++)
	for (int y = 0; y <= elt/2; y++)
		for (int z = 0; z <= elt/2; z++) {
			d = sqrt(pow((h + sh - x), 2) + pow((h + sh - y), 2) + pow((h + sh - z), 2))*step;
			if (abs(d - r) <  step / sqrt(2))
				mat[elt - x - 1][y][elt - z - 1] = mat[elt - x - 1][elt - y - 1][z] = mat[elt - x - 1][elt - y - 1][elt - z - 1] = mat[elt - x - 1][y][z] =
				mat[x][y][elt - z - 1] = mat[x][elt - y - 1][z] = mat[x][elt - y-1][elt - z-1] = mat[x][y][z] = 2;
			else if (d < r)
				mat[elt - x - 1][y][elt - z - 1] = mat[elt - x - 1][elt - y - 1][z] = mat[elt - x - 1][elt - y - 1][elt - z - 1] = mat[elt - x - 1][y][z] =
				mat[x][y][elt - z - 1] = mat[x][elt - y - 1][z] = mat[x][elt - y-1][elt - z-1] = mat[x][y][z] = 1;
			else if (d > r)
				mat[elt - x - 1][y][elt - z - 1] = mat[elt - x - 1][elt - y - 1][z] = mat[elt - x - 1][elt - y - 1][elt - z - 1] = mat[elt - x - 1][y][z] =
				mat[x][y][elt - z - 1] = mat[x][elt - y - 1][z] = mat[x][elt - y-1][elt - z-1] = mat[x][y][z] = 0;
		}
	mat[h+sh][h + sh][h + sh] = 5;
	for (int t = 0; t < elt; t++) {
	//int t = 11;
		for (int i = 0; i < elt; i++) {
			for (int j = 0; j < elt; j++) {
				std::cout << mat[t][i][j] << ' ';
			}
			std::cout << std::endl;
		}
		system("pause");
	}*/
}