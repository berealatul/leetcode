#pragma once
#include <vector>
#include<string>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto& val : operations) {
            if (val.find('-') == -1) x++;
            else x--;
        }
        return x;
    }
};