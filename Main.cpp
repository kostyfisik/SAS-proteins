#include <iostream>
#include <vector>
#include <cmath>
void main() {
	double step = 0.5;
	double r = 2;
	int h = round(r / step), sh=3;
	int elt = 2 * (h + sh);
	int ***mat = new int**[elt];
	for (int i = 0; i <elt; i++)
		mat[i] = new int*[elt];
	for (int i = 0; i < elt; i++)
		for (int j = 0; j < elt; j++)
			mat[i][j] = new int[elt];

	double d = 0;
	//for (int x = 0; x < elt; x++)
	int x = 7;
		for (int y = 0; y <  elt; y++) 
			for (int z = 0; z < elt; z++) {
				d = sqrt(pow(( h+sh - x), 2) + pow((h + sh - y), 2) + pow((h + sh - z), 2));
				//double tn = (h + sh - y) / (h + sh - z);
				if (h - step/2 < d && d < h + step/2)
					mat[x][y][z] = 2;
				else if (d < h)
					mat[x][y][z] = 1;
				else if (d > h)
					mat[x][y][z] = 0;
		}
	mat[h+sh][h + sh][h + sh] = 5;
	//for (int t = 0; t < elt; t++) {
	int t = 7;
		for (int i = 0; i < elt; i++) {
			for (int j = 0; j < elt; j++) {
				std::cout << mat[t][i][j] << ' ';
			}
			std::cout << std::endl;
		}
		system("pause");
	//}
}