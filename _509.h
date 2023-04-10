#pragma once
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;

        if (cache.count(n)) return cache[n]; // recall

        // memorize
        cache[n - 1] = fib(n - 1);
        cache[n - 2] = fib(n - 2);

        return fib(n - 1) + fib(n - 2);
    }
private:
    unordered_map<int, int> cache; // memorization
};