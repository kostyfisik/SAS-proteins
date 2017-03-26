#include <iostream>
#include <vector>
void main() {
	int t = 0;
	int b[4] = { 1,2,3,4 };
	std::vector< (int)4 > a;
	for (int i = 0; i < 3; i++)
			a.push_back(b);
	
	system("pause");
}