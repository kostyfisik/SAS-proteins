#include "SAScore.h"



void SAScore::Gridding(double r, double step) {
	int h = round(r / step), sh = 1;
	elt = 2 * (h + sh + 1) - 1;
	int ***mat = new int**[elt];
	for (int i = 0; i <elt; i++)
		mat[i] = new int*[elt];
	for (int i = 0; i < elt; i++)
		for (int j = 0; j < elt; j++)
			mat[i][j] = new int[elt];
	double d = 0;
	for (int x=0; x <= h+sh; x++) {
		for (int y = 0; y <= h + sh; y++) {
			for (int z = 0; z <= h + sh; z++) {
				d = sqrt(pow((h + sh - x), 2) + pow((h + sh - y), 2) + pow((h + sh - z), 2))*step;
				if (abs(d - r) < step / sqrt(2))
					mat[elt - x - 1][y][elt - z - 1] = mat[elt - x - 1][elt - y - 1][z] = mat[elt - x - 1][elt - y - 1][elt - z - 1] = mat[elt - x - 1][y][z] =
					mat[x][y][elt - z - 1] = mat[x][elt - y - 1][z] = mat[x][elt - y - 1][elt - z - 1] = mat[x][y][z] = 2;
				else if (d < r)
					mat[elt - x - 1][y][elt - z - 1] = mat[elt - x - 1][elt - y - 1][z] = mat[elt - x - 1][elt - y - 1][elt - z - 1] = mat[elt - x - 1][y][z] =
					mat[x][y][elt - z - 1] = mat[x][elt - y - 1][z] = mat[x][elt - y - 1][elt - z - 1] = mat[x][y][z] = 1;
				else if (d > r)
					mat[elt - x - 1][y][elt - z - 1] = mat[elt - x - 1][elt - y - 1][z] = mat[elt - x - 1][elt - y - 1][elt - z - 1] = mat[elt - x - 1][y][z] =
					mat[x][y][elt - z - 1] = mat[x][elt - y - 1][z] = mat[x][elt - y - 1][elt - z - 1] = mat[x][y][z] = 0;
			}
		}
		cout.precision(3);
		cout <<"       " << '\r' << double(x) / double(h + sh) * 100 << '%' << '\r';
	}
	cout << endl;
	mat[h + sh][h + sh][h + sh] = 5;
	r_grid.push_back(mat);

}

void SAScore::PRINT() {
	//for (int x = 0; x < 1; x++)
	int x = 6;
		for (int y = 0; y < elt; y++) {
			for (int z = 0; z < elt; z++)
				cout << r_grid[0][x][y][z]<< ' ';
			cout << endl;
		}
}

SAScore::SAScore(double data[200][4], double r, double step)
{
	std::cout << "initializing of arrays" << std::endl;
	std::cout << "Gridding of solvent " << std::endl;
	//Gridding();
		
}

SAScore::SAScore(double r, double step)
{
	std::cout << "initializing of arrays" << std::endl;
	std::cout << "Gridding of solvent" << std::endl;
	Gridding(r, step);

}

SAScore::~SAScore()
{
}
