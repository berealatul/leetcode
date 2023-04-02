#pragma once
#include <map>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        return modifiedFibonacci(n);
    }
private:
    map<int, int> cache; // memorized

    int modifiedFibonacci(int n) {
        if (cache.count(n)) return cache[n]; // recall form memory
        
        if (n < 2) return 1; // modification done here 

        cache[n - 1] = modifiedFibonacci(n - 1); // memorize
        cache[n - 2] = modifiedFibonacci(n - 2); // memorize

        return modifiedFibonacci(n - 1) + modifiedFibonacci(n - 2);
    }
};