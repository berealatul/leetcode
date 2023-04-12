#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> first, second;
        for (auto& val : nums1) first[val]++;
        for (auto& val : nums2) second[val]++;

        vector<int> ans;
        for (auto& pair : first) {
            if (second.find(pair.first) != second.end()) {
                int minimum = min(pair.second, second[pair.first]);
                while (minimum--) ans.push_back(pair.first);
            }
        }
        return ans;
    }
};