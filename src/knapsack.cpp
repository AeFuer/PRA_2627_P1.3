#include <algorithm>
#include <vector>
#include "knapsack.h"

using namespace std;

vector<vector<int>> memIni(int elNum,int M){

	vector<vector<int>> MEM(elNum+1,vector<int>(M+1,-1));
	
	for(int i = 0; i <= elNum; i++){
		MEM[i][0] = 0;
	}
	for(int i = 0; i <= M; i++){
		MEM[0][i] = 0;
	}
	return MEM;
}

int knapsack(const vector<int> w, const vector<int> v, const int m, vector<vector<int>>& MEM, int ce, int cw){
	
	if(MEM.size() == 0){
		MEM = memIni(v.size(), m);
		ce = w.size()-1;
		cw = m;
	}

	if(MEM[ce+1][cw] >= 0){
		return MEM[ce+1][cw];
	}

	if(cw < w[ce]){
		MEM[ce+1][cw] = knapsack(w,v,m,MEM,ce-1,cw);
	} else{
		MEM[ce+1][cw] = max(knapsack(w,v,m,MEM,ce-1,cw),v[ce]+ knapsack(w,v,m,MEM,ce-1,cw-w[ce]));
	}
	return MEM[ce+1][cw];
}

