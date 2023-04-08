#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer;

        for (int i = 0; i <= n; i++) {
            answer.push_back(countSetBits(i));
        }

        return answer;
    }
private:
    int countSetBits(int n) {
        if (!n) return 0;
        return (n & 1) + countSetBits(n >> 1);
    }
};