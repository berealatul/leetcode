#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int arraySize = nums.size();
        k %= arraySize;
        
        int count = 0, start = 0;        
        int index = start;
        int buffer = nums[start];
        while (count != arraySize) {
            index = (index + k) % arraySize;
            swap(buffer, nums[index]);
            count++;
            
            if (index == start) {
                index = ++start;
                if (index >= arraySize) return;
                buffer = nums[start];
            }
        }
    }
};