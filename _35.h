#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int middle;
        while (start <= end) {
            middle = (static_cast<long>(start) + end) / 2;

            if (nums[middle] == target) return middle;
            if (nums[middle] < target) start = middle + 1;
            else end = middle - 1;
        }
        return start;
    }
};

// recursive method
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return searchInsert(nums, target, 0, nums.size() - 1);
    }
private:
    int searchInsert(vector<int>& nums, int target, int start, int end) {
        if (start > end) return start;

        int middle = (start + end) / 2;
        if (nums[middle] == target) return middle;

        if (nums[middle] < target) return searchInsert(nums, target, middle + 1, end);
        return searchInsert(nums, target, start, middle - 1);
    }
};