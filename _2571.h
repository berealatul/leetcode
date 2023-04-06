#pragma once
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