#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largestSum = INT_MIN;
        int sum = 0;
        for (auto& val : nums) {
            sum += val;
            largestSum = max(largestSum, sum);
            if (sum < 0) sum = 0;
        }
        return largestSum;
    }
};