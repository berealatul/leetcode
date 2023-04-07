#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0, n = grid.size(); i < n; i++) {
            for (int j = 0, m = grid[0].size(); j < m; j++) {
                if (grid[i][j] == 1) {
                    bool edgeTouched = false;
                    int tempCount = 0;
                    dfs(i, j, grid, edgeTouched, tempCount);
                    if (edgeTouched) tempCount = 0;
                    count += tempCount;
                }
            }
        }
        return count;
    }
private:
    void dfs(int i, int j, vector<vector<int>>& grid, bool& edgeTouched, int& count) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || !grid[i][j]) return;
        
        
        if (!(i * j) || i == m - 1 || j == n - 1) edgeTouched = true;
        grid[i][j] = 0;
        count++;

        const short directions = 4;
        const short x[directions] = { 1, -1, 0, 0 };
        const short y[directions] = { 0, 0, 1, -1 };

        for (short k = 0; k < directions; k++) {
            dfs(i + x[k], j + y[k], grid, edgeTouched, count);
        }
    }
};