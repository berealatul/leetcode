#pragma once
#include <vector>
#include "myFunction.h"
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sumTotal = 0;
        int maxVal = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            sumTotal += nums[i];
            // i is being added to sumTotal to avoid truncation while dividing
            int currentVal = (sumTotal + i) / (i + 1);
            if (maxVal < currentVal) {
                maxVal = currentVal;
            }
        }
        return maxVal;
    }
};