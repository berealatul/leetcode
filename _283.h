#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (auto& val : nums) {
            if (val) nums[i++] = val;
        }
        while (i < nums.size()) nums[i++] = 0;
    }
};