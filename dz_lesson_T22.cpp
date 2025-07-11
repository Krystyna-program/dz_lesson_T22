#include <vector>
#include <algorithm>
#include "Computer.h"
using namespace std;

int main()
{
	vector<Computer> comp;

	Computer a("Lenovo", 3.5, 16, true, 18000);
	Computer b("Asus", 2.8, 8, false, 14500);

	comp.push_back(a); // size = 1
	comp.push_back(b); // size = 2
	comp.push_back(Computer("HP", 3.0, 32, true, 23000));

	for (int i = 0; i < comp.size(); i++)
	{
		comp[i].showInfo();
	}
	cout << "===================================\n";
}