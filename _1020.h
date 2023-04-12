#pragma once
#include <vector>
using namespace std;
//1020. Number of Enclaves
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!(i * j) || i == m - 1 || j == n - 1) {
                    if (grid[i][j]) dfs(grid, i, j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) count += grid[i][j];
        }

        return count;
    }
private:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || !grid[i][j]) return;

        grid[i][j] = 0;

        const int direction = 4;
        int x[direction] = { -1, 1, 0, 0 };
        int y[direction] = { 0, 0, 1, -1 };
        for (int k = 0; k < direction; k++) {
            dfs(grid, i + x[k], j + y[k]);
        }
    }
};