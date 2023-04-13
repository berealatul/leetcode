#pragma once
#include <vector>
using namespace std;


// Approach #1: Record Letters Seen [Accepted]
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const int N = 26;
        vector<bool> seen(N, false);
        for (auto& c : letters) seen[c - 'a'] = true;
        for (int i = target - 'a' + 1; i < N; i++) {
            if (seen[i]) return (i + 'a');
        }
        return letters.front();
    }
};

// Approach #2: Linear Scan [Accepted]
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (auto& c : letters) if (c > target) return c;
        return letters.front();
    }
};

// Approach #3: Binary Search [Accepted]
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0, end = letters.size();
        int middle;
        while (start < end) {
            middle = (start + end) / 2;
            if (letters[middle] <= target) start = middle + 1;
            else end = middle;
        }
        return letters[start % letters.size()];
    }
};