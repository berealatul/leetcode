#pragma once
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// print 1D array {1, 2, 3,...}
template<typename T>
void printArray1D(vector<T> data) {
	for (auto& val : data) cout << val << " ";
	cout << endl;
}

// print 2D array {{1,2},{3,4},...}
template<typename T>
void printArray2D(vector<vector<T>> data) {
	for (auto& bucket : data) {
		printArray1D(bucket);
	}
}


// take 1D vector as input with 1, 2, ....
template<typename T>
void inputAsArray1D(vector<T>& data, string& s) {
	string buffer;
	T n;
	for (stringstream input(s); getline(input, buffer, ',');) {
		stringstream temp(buffer);
		temp >> n;
		data.push_back(n);
	}
}

// take 1D vector as input with [1, 2, ....]
template<typename T>
void lcArray1D(vector<T>& data, string& s) {
	s = s.substr(1, s.length() - 2);
	inputAsArray1D(data, s);
}

// take 2D vector as input [[1, 2], [2, 4],....]
template<typename T>
void lcArray2D(vector<vector<T>>& data, string& s, const char C = ']') {
	s = s.substr(0, s.length() - 1);
	string buffer;
	for (stringstream input(s); getline(input, buffer, C);) {
		buffer = buffer.substr(1) + C;
		vector<T> temp;
		lcArray1D(temp, buffer);
		data.push_back(temp);
	}
}
