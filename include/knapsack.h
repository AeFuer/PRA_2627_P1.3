#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>

using namespace std;

vector<vector<int>> memIni(int elNum, int M);

int knapsack(const vector<int> w, const vector<int> v, const int m,vector<vector<int>>& MEM,int ce = 0,int cw = 0);

int knapsackSol(const vector<int> w, const vector<int> v, const int m,vector<int>& s);

#endif
