#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0, n = nums.size(); i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] + nums[i] == target) return { i, j };
            }
        }
        return {};
    }
};