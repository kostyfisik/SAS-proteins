#include <iostream>
#include <fstream>
#include <vector>
#include "SAScore.h"


int main() {
  // TODO Please, provide some comment on m - what does it mean?
	std::vector < std::vector<double> > m(1,{ 0,0, 5});
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
        // TODO Please, provide some comment on SAScore parameter - what does it mean?
        // e.g.
        // Constructor:
        // SAScore<dim> sas_core (m, a, b,)
        //   dim - problem dimension (2 or 3 D)
        //   m   -
        //   a   -
        //   b   - 
	SAScore <2> b(m, 2.5, 0.05);
	//system("pause");
        return 0;
}
