#pragma once
#include <iostream>
#include <unordered_set>
using namespace std;

// Method 1 : general approach
class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> uniqueChar;    
        int substringCount = 1;
        for (auto& c : s) {
            if (uniqueChar.find(c)!= uniqueChar.end()) {
                uniqueChar.clear();
                substringCount++;
            }
            uniqueChar.insert(c);
        }

        return substringCount;
    }
};


// Method 2 : using bit manupulation technique
class Solution {
public:
    int partitionString(string s) {
        int substringCount = 1;

        int previousElements = 0;
        for (auto& c : s) {
            int currentElement = c - 'a';
            if (previousElements & (1 << currentElement)) {
                substringCount++;
                previousElements = 0;
            }
            previousElements = previousElements | (1 << currentElement);
        }

        return substringCount;
    }
};