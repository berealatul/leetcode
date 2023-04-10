#pragma once
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> buffer;
        for (auto& val : nums) {
            if (buffer.find(val) != buffer.end()) return true;
            buffer.insert(val);
        }
        return false;
    }
};