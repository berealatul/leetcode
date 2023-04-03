#pragma once
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        string number = to_string(abs(x));
        auto reversedNum = stol(reverseString(to_string(x)));

        if (reversedNum < min || reversedNum > max) return 0;

        return (x < 0) ? -reversedNum : reversedNum;
    }
private:
    const long min = pow(-2, 31);
    const long max = pow(2, 31) - 1;

    string reverseString(string num) {
        int left = 0, right = num.length() - 1;
        while (left < right) swap(num[left++], num[right--]);
        return num;
    }
};