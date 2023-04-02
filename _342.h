#pragma once
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1) return false;

        if (n == 1) return true;

        if (!(n % 4)) return isPowerOfFour(n / 4);

        return false;
    }
};