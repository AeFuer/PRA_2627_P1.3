#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> memIni(int coinN, int d){

	int infinite = numeric_limits<int>::max()/2;

	vector<vector<int>> m(coinN,vector<int>(d,0);

	for(int i = 0; i < coinN; i++){
		m[i][0] = infinite;
	}
	return m;
}

template<typename T>

vector<T> monedas(const vector<int> m, const int d){

	vector<vector<int>> MEM;
	MEM = memIni(m.size(),d);
	
