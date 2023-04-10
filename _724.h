#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0, rightSum = 0;
        for (auto& val : nums) rightSum += val;

        for (int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];

            if (leftSum == rightSum) return i;            
            
            leftSum += nums[i];            
        }
        
        return -1;
    }
};