#pragma once
#include <iostream>
#include <vector>
#include <bitset>
#include "myFunction.h"
using namespace std;

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<long long> answer;

        
        const int N = 100000;
        bitset<N> bitSetOfNums1;
        long long nums2Sum = 0;
        for (int i = 0, n = nums1.size(); i < n; i++) {
            nums2Sum += nums2[i];
            if (nums1[i]) bitSetOfNums1.set(i);
        }
        
        bitset<N> bitMask;
        for(auto& query : queries) {
            if (query[0] == 1) {
                bitMask.set();
                bitMask <<= query[2] - query[1] + 1;
                bitMask.flip();
                bitMask <<= query[1];

                bitSetOfNums1 ^= bitMask;
            }
            
            if (query[0] == 2) nums2Sum += query[1] * bitSetOfNums1.count();

            if (query[0] == 3) answer.push_back(nums2Sum);
        }

        return answer;
    }
};