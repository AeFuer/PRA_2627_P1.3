#include <iostream>
#include <vector>
#include "monedas.h"

using namespace std;

int main(){
	vector<vector<int>> MEM;
	vector<int> m = {1,4,6};
	int monedaNum = 0;
	monedaNum = maxMonedasMEM(m,8,MEM);
	cout << monedaNum << endl;
	return 0;
}
