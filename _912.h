#pragma once
#include <vector>
using namespace std;

class Solution {
    void mergeSort(vector<int>& list) {
        if (list.size() < 2) return;

        auto middle = list.size() / 2;

        vector<int> left(middle);
        for (auto i = 0; i < middle; i++) left[i] = list[i];

        vector<int> right(list.size() - middle);
        for (auto i = middle; i < list.size(); i++) right[i - middle] = list[i];

        mergeSort(left);
        mergeSort(right);

        merge(left, right, list);
    }

    void merge(vector<int>& left, vector<int>& right, vector<int>& list) {
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) list[k++] = left[i++];
            else list[k++] = right[j++];
        }

        while (i < left.size()) list[k++] = left[i++];
        while (j < right.size()) list[k++] = right[j++];
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums;
    }
};