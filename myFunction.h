#pragma once
#include <iostream>
#include <vector>
using namespace std;


void printInt(vector<int> data) {
	for (auto& val : data) cout << val << " ";
	cout << endl;
}

void printInt2D(vector<vector<int>> data) {
	for (auto& bucket : data) {
		printInt(bucket);
	}
}

