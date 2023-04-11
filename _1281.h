#pragma once
class Solution {
public:
    int subtractProductAndSum(int n) {
        long long pdt = 1;
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit;
            pdt *= digit;
            n /= 10;
        }
        return pdt - sum;
    }
};