#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, n = numbers.size(); i < n; i++) {
            int buffer = target - numbers[i];
            int j = find(numbers, buffer);
            if (j != -1) return { i + 1, j + 1 };
        }
        return {};
    }
private:
    int find(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int middle;
        while (start <= end) {
            middle = (start + end) / 2;

            if (nums[middle] == target) return middle;
            if (nums[middle] > target) end = middle - 1;
            else start = middle + 1;
        }
        return -1;
    }
};