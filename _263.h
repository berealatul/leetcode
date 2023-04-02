#pragma once
class Solution {
public:
    bool isUgly(int n) {
        if (!n) return false;

        if (n == 1) return true;
        
        if (!(n % C)) return isUgly(n / C);
        if (!(n % B)) return isUgly(n / B);
        if (!(n % A)) return isUgly(n / A);
        
        return false;
    }
private:
    const int A = 2, B = 3, C = 5;
};