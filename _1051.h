#pragma once
#include <vector>
#include <map>
using namespace std;

class Solution {
    void bubbleSort(vector<int>& list) {
        bool swapped = true;
        while (swapped) {
            swapped = false;
            for (auto i = 0; i < list.size() - 1; i++) {
                if (list[i] > list[i + 1]) {
                    swap(list[i], list[i + 1]);
                    swapped = true;
                }
            }
        }
    }
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeight = heights;
        bubbleSort(sortedHeight);

        int count = 0;
        for (auto i = 0; i < sortedHeight.size(); i++) {
            if (sortedHeight[i] != heights[i]) count++;
        }
        return count;
    }
};