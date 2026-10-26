#include <algorithm>
#include <vector>
#include "knapsack.h"

using namespace std;

vector<vector<int>> memIni(int elNum,int M){

	vector<vector<int>> MEM(elNum,vector<int>(M+1,-1);
	
	for(int i = 0; i < elNum; i++){
		MEM[i][0] = 0;
		MEM[0][i] = 0;
	}
	return MEM;
}

int knapsack(const vector<int> w, const vector<int> v, const int m, vector<vector<int>>& MEM, const int ce = 0, const int cw = 0){
	
	if(MEM.size() == 0){
		MEM = memIni(v.size(), m);
	}

	if(MEM[ce][cw] >= 0){
		return MEM[ce][cw];
	}

	if(j < w[i]){
		MEM[ce][cw] = knapsack(w,v,m,MEM,ce-1,cw);
	} else{
		MEM[ce][cw] = max(knapsack(w,v,m,MEM,ce-1,cw),v[ce]+ knapsack(w,v,m,MEM,ce-1,cw-w[ce]));
	}
	return MEM[ce][cw];
}

