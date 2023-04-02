#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        for (int i = 1; i <= numRows; i++) {
            vector<int> buffer;
            for (int j = 1; i <= i; i++) {
                buffer.push_back(findPascalElement(i, j));
            }
            answer.push_back(buffer);
        }
        return answer;
    }

    int findPascalElement(int i, int j) {
        if (j == 1 || i == j) return 1;
        return findPascalElement(i - 1, j - 1) + findPascalElement(i - 1, j);
    }
};