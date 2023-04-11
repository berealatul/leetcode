#pragma once
#include <iostream>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string newString;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') newString.pop_back();
            else newString.push_back(s[i]);
        }
        return newString;
    }
};
