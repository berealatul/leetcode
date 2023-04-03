#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> repetitionCount;
        for (auto& val : nums) repetitionCount[val]++;

        vector<vector<int>> twoDArray;
        for (auto& pair : repetitionCount) {            
            while (twoDArray.size() < pair.second) {
                twoDArray.push_back({});
            }

            for (int i = 0; i < pair.second; i++) {
                twoDArray[i].push_back(pair.first);
            }            
        }

        return twoDArray;
    }
};