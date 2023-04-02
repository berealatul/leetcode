#pragma once
#include <map>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (cache.count(n)) return cache[n]; // memorization
        
        if (n < 2) return n;
        
        cache[n - 1] = fib(n - 1); // memorization
        cache[n - 2] = fib(n - 2); // memorization

        return fib(n - 1) + fib(n - 2);
    }
private:
    map<int, int> cache; // memorization
};