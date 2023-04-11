#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        int middle;
        while (start <= end) {
            middle = (static_cast<long>(start) + end) / 2;

            if (arr[middle] > arr[middle - 1] && arr[middle] > arr[middle + 1]) return middle;

            if (arr[middle] > arr[middle - 1]) start = middle;
            else end = middle;
        }

        return -1;
    }
};