#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = INT_MAX;
        int maxProfit = INT_MIN;
        for (auto& val : prices) {
            minimum = min(val, minimum);
            maxProfit = max(maxProfit, val - minimum);
        }
        return maxProfit;
    }
};