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

int guess(int num) {
    if (num > 6) return -1;
    if (num < 6) return 1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        return guessNumber(1, n);
    }
private:
    int guessNumber(int start, int end) {

        if (!guess(start)) return start;
        if (!guess(end)) return end;

        int middle = (static_cast<long>(start) + end) / 2;

        if (!guess(middle)) return middle;
        if (guess(middle) < 0) return guessNumber(start, middle);
        return guessNumber(middle, end);
    }
};