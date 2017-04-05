#include <iostream>
#include <vector>
#include <cmath>
#include "SAScore.h"
void main() {
	std::vector < std::vector<double> > m(1, { 1,2,3, 3 });
	m.push_back({ 10,2,3,5 });
	SAScore <> b (m, 1, 0.5);
	system("pause");
}