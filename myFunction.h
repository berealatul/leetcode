#pragma once
#include <iostream>
#include <vector>
using namespace std;

void printInt2D(vector<vector<int>>& data);
void printInt(vector<int>& data);

void printInt2D(vector<vector<int>>& data) {
	for (auto& bucket : data) {
		if (bucket.empty()) cout << "Empty!";
		else {
			for (auto& val : bucket) cout << val << " ";
		}
		cout << endl;
	}
}

void printInt(vector<int>& data) {
	for (auto& val : data) cout << val << " ";
	cout << endl;
}