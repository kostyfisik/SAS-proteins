#include <iostream>
#include <fstream>
#include <vector>
#include "SAScore.h"


void main() {
	std::vector < std::vector<double> > m(1,{ 0,0, 10});
	//m.push_back({ 10,2,3,3 });
	/*std::vector<double> temp(5);
	std::vector < std::vector<double> > m(0, std::vector<double>(5));

	std::ifstream datafile("data.txt");
	while (!datafile.eof()) {
		for (int i = 0; i < 5; ++i)
			datafile >> temp[i];
		m.push_back(temp);
	}
	for (int i = 0; i < m.size(); ++i){
		m[i][4] = m[i][0];
		m[i].erase(m[i].begin());
	}*/
	SAScore <2> b(m, 4, 0.5);
	system("pause");
}