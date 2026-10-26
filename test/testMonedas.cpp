#include <iostream>
#include <vector>
#include <limits>
#include <string>

#include "monedas.h"

using namespace std;

void test(const string& name, const vector<int> m, const int d, const int solution){

	vector<vector<int>> MEM;
	
	int infinite = numeric_limits<int>::max() / 2;
	int result = maxMonedasMEM(m,d,MEM);

	cout << "---" << name << "---" << endl <<  endl;
	cout << "Coins: ";

	for(int i = 0; i  < m.size()-1; i++){
		cout << m[i] << ", ";
	}

	cout << m[m.size()-1] << "}" << endl;
	cout << "Target: " << d << endl;

	cout << "Result: ";
	if(result >= infinite){
		cout << "No Solution Found" << endl;
	}else{
		cout << result << " coins" << endl;
	}
	
	if((solution == -1 && result >= infinite) || result == solution){
		cout <<"[TEST SUCCESS]";
	} else {
		cout <<"[TEST FAILURE - SOLUTION: " << (solution == -1 ? "No Solution" : to_string(solution)) << "]";
	}
	cout << endl << endl;
}


int main(){
	
	cout << "------ TEST MONEDAS PD ------" << endl << endl;

	vector<int> m = {1, 4, 6};
	test("Test 1 - Base", m, 8, 2);

	m = {2, 4, 5};
	test("Test 2 - No 1, Possible", m, 10, 2);

	m = {2, 4, 6};
	test("Test 3 - No 1, Impossible",m, 7, -1);

	m = {3, 5};
	test("Test 4: Skip Largest", m, 6, 2);
	
	m = {1, 4, 10};
	test("Test 5: 1 coin", m, 10, 1);

	test("Test 6: Null target", m, 0, 0);

	return 0;
}
