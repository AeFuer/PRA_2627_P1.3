#include <iostream>
#include <vector>
#include "knapsack.h"

using namespace std;

int main(){
	vector<int> w = {9,6,5};
	vector<int> v = {38,40,24};
	vector<vector<int>> MEM;

	int max = knapsack(w,v,15,MEM);

	cout << max << endl;

	return 0;
}
