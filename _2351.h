#pragma once
#include <iostream>
using namespace std;
class Solution {
public:
    char repeatedCharacter(string s) {
        int value = 0;
        int tempVal;
        for(auto& c : s) {
            tempVal = 1 << (c - 'a');
            if (value & tempVal) return c;
            value |= tempVal;
        }

        return s.back();
    }
};