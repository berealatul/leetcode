#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({ 1 });
        if (numRows < 2) return ans;

        vector<int> last = { 1, 1 };
        ans.push_back(last);

        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < i; j++) last[j] = ans.back()[j] + ans.back()[j - 1];
            
            last.push_back(1);
            ans.push_back(last);
        }

        return ans;
    }
};