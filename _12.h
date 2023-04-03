#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        for (int i = 0; i < symbol.size(); i++) {
            short val = num / number[i];
            while (val) {
                roman += symbol[i];
                val--;
            }
            
            num %= number[i];
            roman += updateNumberAndAddSymbol(num);

            if (!num) break;
        }
        return roman;
    }
private:
    const vector<int> number = { 1000, 500, 100, 50, 10, 5, 1 };
    const vector<char> symbol = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };

    string updateNumberAndAddSymbol(int& currentNumber) {
        if (currentNumber >= 900 && currentNumber < 1000) {
            currentNumber -= 900;
            return "CM";
        }
        if (currentNumber >= 400 && currentNumber < 500) {
            currentNumber -= 400;
            return "CD";
        }
        if (currentNumber >= 90 && currentNumber < 100) {
            currentNumber -= 90;
            return "XC";
        }
        if (currentNumber >= 40 && currentNumber < 50) {
            currentNumber -= 40;
            return "XL";
        }
        if (currentNumber >= 9 && currentNumber < 10) {
            currentNumber -= 9;
            return "IX";
        }
        if (currentNumber == 4) {
            currentNumber -= 4;
            return "IV";
        }
        return "";
    }
};