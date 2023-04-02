#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string restored = s;
        for (int i = 0, n = s.length(); i < n; i++) {
            restored[indices[i]] = s[i];
        }
        return restored;
    }
};