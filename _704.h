#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        int middle;
        while (start <= end) {
            middle = (start + end) / 2;

            if (nums[middle] == target) return middle;
            if (nums[middle] < target) start = middle + 1;
            else end = middle - 1;
        }

        return -1;
    }
};