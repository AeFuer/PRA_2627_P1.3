#include <limits>
#include <algorithm>
#include <vector>
#include "monedas.h"


using namespace std;

vector<vector<int>> memIni(int coinN, int d){

	int infinite = numeric_limits<int>::max()/2;

	vector<vector<int>> m(coinN,vector<int>(d+1,infinite));

	for(int i = 0; i < coinN; i++){
		m[i][0] = 0;
	}
	return m;
}

int maxMonedasMEM(const vector<int> m, const int d, vector<vector<int>>& MEM){
	
	int infinite = numeric_limits<int>::max()/2;
	int min_val = infinite;

	MEM = memIni(m.size(),d);

	for(int j = 1; j <= d; j++){
		if(j >= m[0] && MEM[0][j-m[0]] != infinite){
			MEM[0][j] = 1 + MEM[0][j-m[0]];
		}
	}
	for(int i = 1; i < m.size(); i++){
		for(int j = 1; j <= d; j++){
			if(j < m[i] || MEM[i][j-m[i]] == infinite){
				MEM[i][j] = MEM[i-1][j];
			} else if(MEM[i-1][j] != infinite){
				MEM[i][j] = min(MEM[i-1][j],1+MEM[i][j-m[i]]);
			} else{
				MEM[i][j] = 1 + MEM[i][j-m[i]];
			}
		}
	}

	min_val = MEM[m.size()-1][d];
	return min_val;
}

vector<int> monedas(const vector<int> m, const int d){
	
	vector<vector<int>> MEM;
	int infinite = numeric_limits<int>::max()/2;

	int min = maxMonedasMEM(m,d,MEM);
	
	vector<int> s(m.size(),0);
	
	if(min >= infinite){
		return s;
	}

	int i = m.size()-1;
	int j = d;
	while(j > 0){
		if(i == 0 || MEM[i][j] != MEM[i-1][j]){
			s[i] = s[i] + 1;
			j = j - m[i];
		} else {
			i = i-1;
		}
	}
	return s;
}

