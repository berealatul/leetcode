#pragma once
#include <cstdint>
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int countSetBit = 0;
        while (n)
        {
            if (n & 1)
            {
                countSetBit++;
            }
            n >>= 1;
        }
        return countSetBit;
    }
};