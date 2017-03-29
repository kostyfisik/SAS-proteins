#include "SAScore.h"

bool SAScore::sort_by_value(const vector <int>& vec1, const vector <int>& vec2) {
	return vec1[3] < vec2[3];
}
bool SAScore::sort_by_coord(const vector <int>& vec1, const vector <int>& vec2) {
	if (vec1[0] == vec2[0]) {
		if (vec1[1] == vec2[1]) {
			return vec1[2] < vec2[2];
		}
		else return vec1[1] < vec2[1];
		}
	else
		return vec1[0] < vec2[0];
}

void SAScore::GriddingMolecule(double r, double step) {
	int h = round(r / step);
	elt = 2 *h + 1;
	int ***mat = new int**[elt];
	for (int i = 0; i <elt; i++)
		mat[i] = new int*[elt];
	for (int i = 0; i < elt; i++)
		for (int j = 0; j < elt; j++)
			mat[i][j] = new int[elt];
	double d = 0;
	for (int x=0; x <= h; x++) {
		for (int y = 0; y <= h; y++) {
			for (int z = 0; z <= h; z++) {
				d = sqrt(pow((h - x), 2) + pow((h - y), 2) + pow((h - z), 2))*step;
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
		cout <<"       " << '\r' << double(x) / double(h) * 100 << '%' << '\r';
	}
	cout << endl;
	mat[h][h][h] = 5;
	//if (solvent) 
		r_grid.push_back(mat);

}
//void SAScore::GriddingTotal( ) {

//}

void SAScore::PRINT() {
	for (int x = 0; x < elt; x++) {
		for (int y = 0; y < elt; y++) {
			for (int z = 0; z < elt; z++)
				cout << r_grid[0][x][y][z] << ' ';
			cout << endl;
		}
		cout << endl;
	}
}

SAScore::SAScore(double data[SIZE][4], double r, double step)
{
	//std::cout << "Initializing of arrays" << std::endl;
	std::cout << "Gridding of solvent " << std::endl;
	GriddingMolecule(r, step);

	int x = 0, y = 0, z = 0;

	std::cout << "Gridding of moleculs of protein" << std::endl;
	vector <int> coord(4);
	int d = 0;
for (int i = 0; i < SIZE; i++) {
	x = round(data[i][0] / step);
	y = round(data[i][1] / step);
	z = round(data[i][2] / step);
	GriddingMolecule(data[i][3], step);
	for (int m = 0; m < elt; m++) {
		for (int n = 0; n < elt; n++) {
			for (int o = 0; o < elt; o++) {
				coord[0] = x + m - (elt - 1) / 2;
				coord[1] = y + n - (elt - 1) / 2;
				coord[2] = z + o - (elt - 1) / 2;
				coord[3] = r_grid[1][m][n][o];
				surface.push_back(coord);
			}
		}
	}
	
	r_grid.pop_back();
}
	sort(surface.begin(),surface.end(), sort_by_coord);
	for (int x = 0; x < surface.size(); x++) {
		for (int y = 0; y < surface[x].size(); y++) {
			cout << surface[x][y] << ' ';
			}
		cout << endl;
	}
}

SAScore::SAScore(double r, double step)
{
	std::cout << "initializing of arrays" << std::endl;
	std::cout << "Gridding of solvent" << std::endl;
	GriddingMolecule(r, step);

}

SAScore::~SAScore()
{
}
