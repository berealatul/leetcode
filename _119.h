#pragma once
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rowElements(rowIndex + 1, 1);
        for (int j = 0; j <= rowIndex; j++) {
            rowElements[j] = findPascalElement(rowIndex, j);
        }
        return rowElements;
    }
private:
    map<int, map<int, int>> cache; // memorizarion

    int findPascalElement(int i, int j) {
        if (cache.count(i) && cache[i].count(j)) return cache[i][j]; // memorizarion

        if (j == 0 || i == j) return 1;
        
        cache[i - 1][j - 1] = findPascalElement(i - 1, j - 1); // memorizarion
        cache[i - 1][j] = findPascalElement(i - 1, j); // memorizarion
        
        return findPascalElement(i - 1, j - 1) + findPascalElement(i - 1, j);
    }
};