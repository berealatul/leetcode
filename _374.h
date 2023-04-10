#pragma once
#include <iostream>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

// recursive method
class Solution {
public:
    int guessNumber(int n) {
        return guessNumber(1, n);
    }
private:
    int guessNumber(int start, int end) {
        int middle = (static_cast<long>(start) + end) / 2;
        int val = guess(middle);

        if (!val) return middle;

        if (val < 0) return guessNumber(start, middle - 1);
        return guessNumber(middle + 1, end);
    }
};

// iterative method
class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int middle;
        while (start <= n) {
            middle = (start + n) / 2;
            int val = guess(middle);

            if (!val) break;
            if (val < 0) n = middle - 1;
            else start = middle + 1;
        }
        return middle;
    }
};