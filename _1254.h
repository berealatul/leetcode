#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((!i || !j || i == m - 1 || j == n - 1) && !grid[i][j]) {
                    dfs(grid, i, j);
                }
            }
        }

        int totalIsland = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (!grid[i][j]) {
                    dfs(grid, i, j);
                    totalIsland++;
                }
            }
        }

        return totalIsland;
    }
private:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j]) return;

        grid[i][j] = 1;

        const int direction = 4;
        int x[direction] = { 1, -1, 0, 0 };
        int y[direction] = { 0, 0, 1, -1 };
        for (int k = 0; k < direction; k++) {
            dfs(grid, i + x[k], j + y[k]);
        }
    }
};