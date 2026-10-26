#include <iostream>
#include <vector>
#include <string>
#include "knapsack.h"

using namespace std;

void test(const string name, const vector<int> w, const vector<int> v, const int M, const int solution){

	cout <<"---"<<name<<"---"<<endl<<endl;
	
	vector<vector<int>> MEM;

	cout << "Max Capacity: " << M << endl;

	cout << "Elements:" << endl;

	cout << "-> Weight: {";
	for(int i = 0; i < w.size()-1; i++){
		cout << w[i] << ", ";
	}
	cout << w[w.size()-1]<<"}" << endl;
	
	cout << "-> Value:  {";
	for(int i = 0; i < v.size()-1; i++){
		cout<< v[i] << ", ";
	}
	cout << v[v.size()-1]<<"}" << endl;

	int max = knapsack(w,v,M,MEM);

	cout << "Result: ";
	if(max == 0){
		cout << "Nothing fits" << endl;
	}else{
		cout << max << endl;
	}
	
	if(max == solution){
		cout << "[TEST SUCCESS]" << endl;
	}else{
		cout << "[TEST FAILURE - SOLUTION: " << solution << "]" << endl;
	}

	cout << endl;
}

int main(){

	cout << "------ TESTS ------" << endl << endl;
	
	vector<int> w = {9,6,5};
	vector<int> v = {38,40,24};
	test("---Test 1: Default 1---",w,v,15,78);

	w = {1,3,2,4};
	v = {10,20,15,20};
	test("---Test 2: Default 2---",w,v,5,35);

	test("---Test 3: 0 Capacity---",w,v,0,0);

	w ={100,200,300};
	v ={9999,9999,9999};
	test("---Test 4: Nothing Fits---",w,v,10,0);

	w = {1,2,3};
	v = {10,20,30};
	test("---Test 5: Everything Fits---",w,v,20,60);

	w = {5, 4, 3};
	v = {10,9,9};
	test("---Test 6: Ignore Highest---",w,v,7,18);

	w = {3, 4, 5};
	v = {9, 9, 10};
	test("---Test 7: Test 6 Inverted---",w,v,7,18);

	return 0;
}
