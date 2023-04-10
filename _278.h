#pragma once

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        while (start <= n) {
            int middle = (static_cast<long>(start) + n) / 2;
            if (isBadVersion(middle)) n = middle - 1;
            else start = middle + 1;
        }
        return start;
    }
};

class Solution {
public:
    int firstBadVersion(int n) {
        return firstBadVersion(1, n);
    }

private:
    int firstBadVersion(int start, int end) {
        if (start > end) return start;

        int middle = (static_cast<long>(start) + end) / 2;
        if (isBadVersion(middle)) return firstBadVersion(start, middle - 1);
        return firstBadVersion(middle + 1, end);
    }
};