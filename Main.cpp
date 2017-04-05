#include <iostream>
#include <vector>
#include <cmath>
#include "SAScore.h"
void main() {
	std::vector < std::vector<double> > m(1, { 1,2,3, 0.5 });
	SAScore <2> b (m, 1, 0.5);
	system("pause");
}