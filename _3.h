#pragma once
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> previous = {};
        int longest = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            for (int j = i; j < n; j++) {
                if (!previous.empty() && previous.count(s[j])) break;
                previous.insert(s[j]);
            }
            longest = max(longest, static_cast<int>(previous.size()));
            previous.clear();
        }
        return longest;
    }
};