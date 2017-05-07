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



/*
void SAScore::GriddingMolecule_(double r, double step) {
int h = round(r / step);
elt_ = 2 *h + 1;
int ***mat = new int **[elt_];
for (int i = 0; i <elt_; i++)
mat[i] = new int*[elt_];
for (int i = 0; i < elt_; i++)
for (int j = 0; j < elt_; j++)
mat[i][j] = new int[elt_];
double d = 0;
for (int x = 0; x <elt_; x++) {
for (int y = 0; y < elt_; y++) {
for (int z = 0; z < elt_; z++) {
d = sqrt(pow((h - x), 2) + pow((h - y), 2) + pow((h - z), 2))*step;
if ((r-d) >= 0 && (r - d) <= step / sqrt(2))
mat[x][y][z] = 2;
else if (d < r)
mat[x][y][z] = 1;
else if (d > r)
mat[x][y][z] = 0;
}
}
std::cout.precision(3);
std::cout <<"       " << '\r' << double(x) / double(h) * 100 << '%' << '\r';
}
std::cout << std::endl;
mat[h][h][h] = 5;
//if (solvent)
r_grid_.push_back(mat);
for (int x = 0; x < elt_; x++) {
for (int y = 0; y < elt_; y++) {
for (int z = 0; z < elt_; z++)
std::cout << mat[x][y][z] << ' ';
std::cout << std::endl;
}
std::cout << std::endl;
system("pause");
}


}


for (int i = 0; i < SIZE; i++) {
	x = round(data[i][0] / step);
	y = round(data[i][1] / step);
	z = round(data[i][2] / step);
	GriddingMolecule_(data[i][3], step);
	for (int m = 0; m < elt_; m++) {
		for (int n = 0; n < elt_; n++) {
			for (int o = 0; o < elt_; o++) {
				coord[0] = x + m - (elt_ - 1) / 2;
				coord[1] = y + n - (elt_ - 1) / 2;
				coord[2] = z + o - (elt_ - 1) / 2;
				coord[3] = r_grid_[1][m][n][o];
				surface.push_back(coord);
			}
		}
	}

	r_grid_.pop_back();
}*/
/*sort(surface.begin(),surface.end(), SortByCoord_);
for (int x = 0; x < surface.size(); x++) {
for (int y = 0; y < surface[x].size(); y++) {
std::cout << surface[x][y] << ' ';
}
std::cout << std::endl;
}*/

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
}

template <int dim>
bool SAScore<dim>::RadiusCheck_(const double r) {
	for (auto i : molecule_templates_)
		if (r == i.r) {
			exist_molecule_template_ = i;
			return true;
		}
	return false;
}

template <int dim>
bool SAScore<dim>::SortByValue_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	return vec1[dim] < vec2[dim];
}

template <int dim>
bool SAScore<dim>::SortByCoord_(const std::vector <int>& vec1, const std::vector <int>& vec2) {
	if (vec1[0] == vec2[0]) {
		if (vec1[1] == vec2[1]) {
			if (vec1[2] == vec2[2]) {
				return vec1[3] < vec2[3];
			}
			else return vec1[2] < vec2[2];
		}
		else return vec1[1] < vec2[1];
	}
	else
		return vec1[0] < vec2[0];
}*/