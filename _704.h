#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int middle = start + ((end - start) / 2);
            
            if (middle == start || middle == end) {
                if (nums[start] == target) return start;
                if (nums[end] == target) return end;
                break;
            }

            if (nums[middle] == target) return middle;
            if (target > nums[middle]) start = middle;
            if (target < nums[middle]) end = middle;
        }
        return -1;
    }
};