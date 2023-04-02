#pragma once
#include <vector>
#include <algorithm>
#include "myFunction.h"
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int> pairs(spells.size(), 0);
        sort(potions.begin(), potions.end());
        
        for (int i = 0, n = spells.size(); i < n; i++) {

            auto minValue = success / spells[i];
            if (success % spells[i]) minValue++;

            pairs[i] = countPairs(minValue, potions);
        }

        return pairs;
    }
private:
    int countPairs(long long& minValue, vector<int>& potions) {

        int left = 0;
        int right = potions.size() - 1;

        while (left <= right) {
            auto middle = left + ((right - left) / 2);

            if (potions[middle] >= minValue) right = middle - 1;
            else left = middle + 1;
        }

        return potions.size() - left;
    }
};