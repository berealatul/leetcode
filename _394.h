#pragma once
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        decodeStrings(s);
        return s;
    }
private:
    void decodeStrings(string& s) {
        auto index = s.find(']');

        if (index == -1) return;
        
        int start = index;
        while (s[start] != '[') start--;

        string buffer = s.substr(start + 1, index - start - 1);        
        int xtimes = repetitionCount(s, start); // also updating start                

        s.replace(start, index - start + 1, repeatString(buffer, xtimes));

        decodeStrings(s);
    }

    string repeatString(string s, int times) {
        if (times == 1) return s;
        return s + repeatString(s, times - 1);
    }

    int repetitionCount(string& s, int& start) {
        int end = start;

        while (start) {
            if (isdigit(s[start - 1])) start--;
            else break;
        }

        return stoi(s.substr(start, end - start));
    }
};