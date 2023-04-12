#pragma once
class Solution {
public:
    bool isPerfectSquare(int num) {
        long start = 1, end = num;
        long middle;
        while (start <= end) {
            middle = (start + end) / 2;
            auto square = middle * middle;
            
            if (square == num) return true;

            if (square > num) end = middle - 1;
            else start = middle + 1;

        }
        return false;
    }
};