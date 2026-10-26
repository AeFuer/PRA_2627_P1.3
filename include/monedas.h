#ifndef MONEDAS_H
#define MONEDAS_H

#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> memIni(int coinN, int d);

int maxMonedasMEM(const vector<int> m, const int d, vector<vector<int>>& MEM);

#endif
