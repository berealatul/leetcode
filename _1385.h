#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        for (auto& val1 : arr1) {
            bool isExist = false;

            for (auto& val2 : arr2) {
                if (abs(val1 - val2) <= d) isExist = true;
            }

            if (!isExist) count++;
        }

        return count;
    }
};