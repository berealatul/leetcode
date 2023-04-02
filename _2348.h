#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        
        int startIndex = -1;
        bool zeroFound = false;

        for (int i = 0, n = nums.size(); i < n; i++) {
            if (!nums[i] && !zeroFound) {
                startIndex = i;
                zeroFound = true;
            }
            
            if (zeroFound && nums[i]) {
                count += nNaturalNumberSum(i - startIndex);
                zeroFound = false;
            }

            if (zeroFound && i == n - 1) {
                count += nNaturalNumberSum(i - startIndex + 1);
                zeroFound = false;
            }
        }
        return count;
    }
private:
    long long nNaturalNumberSum(long n) {
        return ((1 + static_cast<long long>(n)) * n) / 2;
    }
};