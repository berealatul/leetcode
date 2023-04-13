#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int N = s1.size();
        vector<int> diff;
        for (int i = 0; i < N; i++) {
            if (s1[i] != s2[i]) diff.push_back(i);
            if (diff.size() > 2) return false;
        }

        if (diff.empty()) return true;
        if (diff.size() == 2) swap(s2[diff[0]], s2[diff[1]]);

        return s1 == s2;
    }
};