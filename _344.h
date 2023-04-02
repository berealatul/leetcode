#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> ans;
        reverseString(s, ans);
        s = ans;
    }
private:
    void reverseString(vector<char>& s, vector<char>& ans, int index = 0) {
        if (index == s.size()) return;
        reverseString(s, ans, index + 1);
        ans.push_back(s[index]);
    }
};