#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>

vector<vector<int>> memIni(int elNum, int M);

int knapsack(const vector<int> w, const vector<int> v, const int m,vector<vector<int>>& MEM,const int ce = 0,const int cw = 0);

#endif
