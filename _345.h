#pragma once
#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        bool leftVowelFound = false, rightVowelFound = false;
        string vowels = "aeiou";

        while (left < right) {
            if (!leftVowelFound) {
                if (vowels.find(tolower(s[left])) == -1) left++;
                else leftVowelFound = true;
            }

            if (!rightVowelFound) {
                if (vowels.find(tolower(s[right])) == -1) right--;
                else rightVowelFound = true;
            }

            if (leftVowelFound && rightVowelFound) {
                swap(s[left++], s[right--]);
                leftVowelFound = rightVowelFound = false;
            }
        }
        return s;
    }
};