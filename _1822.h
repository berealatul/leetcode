#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negativeCount = 0;
        for (auto& val : nums) {
            if (!signFunc(val)) return 0;
            if (signFunc(val) < 0) negativeCount++;
        }

        return negativeCount % 2 ? -1 : 1;
    }
private:
    int signFunc(int& x) {
        if (!x) return x;
        if (x < 0) return -1;
        return 1;
    }
};