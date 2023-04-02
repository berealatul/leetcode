#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        /* Euclid's Division Algorithm
            a = bq + r
            where 0 <= r < b and b > 0

            size = nums.size();
            originalVal = currentElement;
            newVal = nums[currentElement];
            modifiedVal = originalVal + (size * newVal);

            now in future if we want to access originalValue them
            originalVal = modifiedVal / size;
            newVal = modifiedVal % size;
        */

        for (int i = 0, n = nums.size(); i < n; i++) {
            // using modulas here "nums[nums[i]] % n" to get original value 
            // because we are modifing elements in nums and it is possible 
            // that the element we are accessing might have been modified
            nums[i] += (nums[nums[i]] % n) * n;
        }

        for (int i = 0, n = nums.size(); i < n; i++) nums[i] /= n;

        return nums;
    }
};