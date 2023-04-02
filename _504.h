#pragma once
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        
        bool isNegative = num < 0;
        num = abs(num);

        string number;
        while (num >= 7) {
            number += to_string(num % 7);
            num /= 7;
        }
        number += to_string(num);
        
        reverseString(number);

        if(isNegative) return "-" + number;
        return number;
    }
private:
    string reverseString(string& s) {
        int start = 0;
        int end = s.length() - 1;
        while (start < end) swap(s[start++], s[end--]);
        return s;
    }
};