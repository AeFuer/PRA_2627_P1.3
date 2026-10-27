#include <iostream>
#include <vector>
#include <limits>
#include <string>

#include "monedas.h"

using namespace std;

void test(const string& name, const vector<int> m, const int d, const vector<int> solution){
	
	int infinite = numeric_limits<int>::max() / 2;
	vector<int> s = monedas(m,d);

	cout << "---" << name << "---" << endl <<  endl;
	cout << "Coins: {";

	for(int i = 0; i  < m.size()-1; i++){
		cout << m[i] << ", ";
	}
	cout << m[m.size()-1] << "}" << endl;

	cout << "Target: {";
	for(int i = 0; i < solution.size()-1; i++){
		cout << solution[i] << ", ";
	}
	cout << solution[solution.size()-1]<< "}"<<endl;

	cout << "Result: {";
	for(int i = 0; i < s.size()-1; i++){
		cout << s[i] << ", ";
	}
	cout << solution[solution.size()-1] << "}" << endl;

	bool success = true;

	for(int i = 0; i < s.size()-1; i++){
		success = success && (s[i] == solution[i]);
	}

	if(success){
		cout <<"[TEST SUCCESS]";
	} else {
		cout <<"[TEST FAILURE]";
	}
	cout << endl << endl;
}


int main(){
	
	cout << "------ TEST MONEDAS PD ------" << endl << endl;

	vector<int> m = {1, 4, 6};
	test("Test 1 - Base", m, 8, {0, 2, 0});

	m = {2, 4, 5};
	test("Test 2 - No 1, Possible", m, 10, {0, 0, 2});

	m = {2, 4, 6};
	test("Test 3 - No 1, Impossible",m, 7, {0, 0, 0});

	m = {3, 5};
	test("Test 4: Skip Largest", m, 6, {2, 0});
	
	m = {1, 4, 10};
	test("Test 5: 1 coin", m, 10, {0, 0, 1});

	test("Test 6: Null target", m, 0, {0, 0, 0});

	return 0;
}
