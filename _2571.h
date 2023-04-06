#pragma once
class Solution {
public:
    int minOperations(int n) {
        if (n == 1 || n == 0) return n;
        int val = 1;
        while (val < n) val <<= 1;

        return 1 + min(minOperations(val - n), minOperations(n - (val >> 1)));
    }
};

class Solution {
public:
    int minOperations(int n) {
        int count = 0;
        while (n) {
            if ((n & 1) && ((n >> 1) & 1)) {
                count++;
                n++;
            }

            if (n & 1) count++;
            n >>= 1;
        }

        return count;
    }
};