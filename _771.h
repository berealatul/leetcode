#pragma once
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char, int> frequencies;
        for (auto& letter : stones) {
            frequencies[letter]++;
        }
        
        int count = 0;
        for (auto& letter : jewels) count += frequencies[letter];
        return count;
    }
};