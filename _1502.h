#pragma once
#include <vector>
using namespace std;

// 1502. Can Make Arithmetic Progression From Sequence
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        const int diff = arr[1] - arr[0];
        for (int i = 1, n = arr.size(); i < n - 1; i++) {
            if (arr[i + 1] - arr[i] != diff) return false;
        }
        return true;
    }
};