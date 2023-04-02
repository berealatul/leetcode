#pragma once
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> repetitionCount;
        for (auto& val : arr1) repetitionCount[val]++;

        int index = 0;
        for (auto& val : arr2) {
            while (repetitionCount[val]--) arr1[index++] = val;
        }
        
        for (auto& pair : repetitionCount) {
            while (pair.second > 0) {
                arr1[index++] = pair.first;
                repetitionCount[pair.first]--;
            }
        }
        return arr1;
    }
};