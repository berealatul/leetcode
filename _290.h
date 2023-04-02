#pragma once
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        map<char, string> keyValue;
        map<string, char> valueKey;
        int start = 0;
        int index = 0;

        for (auto c : pattern) {
            if (index > s.length()) return false;

            while (isalpha(s[index])) index++;
            string word = s.substr(start, index - start);            

            if (keyValue.count(c) && keyValue[c] != word) return false;
            if (valueKey.count(word) && valueKey[word] != c) return false;

            keyValue[c] = word;
            valueKey[word] = c;

            start = ++index;
        }

        if (index < s.length()) return false;

        return true;
    }
};