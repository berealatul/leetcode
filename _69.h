#pragma once
class Solution {
public:
    int mySqrt(int x) {
        if (!x) return x;

        int start = 1, end = x, mid;
        while (true) {
            mid = (start + end) / 2;

            if (mid > x / mid) end = mid - 1;
            else {
                if (mid + 1 > x / (mid + 1)) return mid;
                start = mid + 1;
            }
        }        
    }
};