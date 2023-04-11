#pragma once
#include <vector>
#include "myFunction.h"
using namespace std;

//88. Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;
        int right = n - 1;
        int index = m + n - 1;
        while (left >= 0 && right >= 0) {
            if (nums1[left] > nums2[right]) {
                nums1[index--] = nums1[left--];
            }
            else nums1[index--] = nums2[right--];
        }

        while (left >= 0) nums1[index--] = nums1[left--];

        while (right >= 0) nums1[index--] = nums2[right--];
    }
};