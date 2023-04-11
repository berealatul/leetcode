#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size();
        vector<int> ans(j, 0);
        j--;

        int index = j;
        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])) {
                ans[index--] = pow(nums[i++], 2);
            }
            else ans[index--] = pow(nums[j--], 2);
        }

        return ans;
    }
};