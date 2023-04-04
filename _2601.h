#pragma once
#include <iostream>
#include <vector>
#include "myFunction.h"
using namespace std;

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        while (!strictlyIncreasing(nums)) {
            for (int i = nums.size() - 1; i > 0; i--) {

                if (nums[i - 1] >= nums[i]) {
                    short prime = previousPrime(nums[i - 1]);
                    
                    if (nums[i - 1] - prime < nums[i]) {

                        while (nums[i - 1] - previousPrime(prime) < nums[i]) {
                            prime = previousPrime(prime);
                        }

                        nums[i - 1] -= prime;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
private:
    bool strictlyIncreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) return false;
        }
        return true;
    }

    bool isPrime(int num) {
        if (num < 2) return false;

        for (int i = 2; i < num; i++) if (!(num % i)) return false;
        
        return true;
    }

    int previousPrime(int num) {
        for (int i = num - 1; i > 1; i--) if (isPrime(i)) return i;
        return -1;
    }
};