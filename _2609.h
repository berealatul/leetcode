#pragma once
#include <string>
using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        bool zeroFound = false, oneFound = false;
        int countZero = 0;
        int countOne = 0;
        int maxLength = 0;

        for (int i = 0, n = s.size(); i < n;  i++) {
            if (!zeroFound && !oneFound && s[i] == '0') {
                countZero++;
                zeroFound = true;
            }
            else if (zeroFound && !oneFound && s[i] == '0') countZero++;
            else if (zeroFound && !oneFound && s[i] == '1') {
                oneFound = true;
                countOne++;
            }
            else if (zeroFound && oneFound && s[i] == '1') countOne++;
            
            if (oneFound && ((zeroFound && s[i] == '0') || i == n - 1)) {
                maxLength = max(2 * min(countZero, countOne), maxLength);
                countZero = 1;
                countOne = 0;
                oneFound = false;
            }
        }
        return maxLength;
    }
};