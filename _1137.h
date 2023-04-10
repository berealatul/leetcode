#pragma once
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (!n) return 0;
        if (n == 1 || n == 2) return 1;

        if (cache.find(n) != cache.end()) return cache[n];
        cache[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);

        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
private:
    unordered_map<int, int> cache;
};