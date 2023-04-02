#pragma once
#include <string>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        short ASCII_VAL_ZERO = 48;
        int maximum = -1;
        for (int i = 0; i < n.length(); i++) {
            maximum = max(maximum, n[i] - ASCII_VAL_ZERO);
        }
        return maximum;
    }
};