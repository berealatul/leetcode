#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        const short m = grid.size(), n = grid[0].size();

        for (short i = 0; i < m; i++) {
            for (short j = 0; j < n; j++) {
                if ((!(i * j) || i == m - 1 || j == n - 1) && grid[i][j] == 0) {
                    dfs(i, j, grid);
                }
            }
        }

        short count = 0;
        for (short i = 1; i < m - 1; i++) {
            for (short j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
private:
    void dfs(const short i, const short j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 0) return;

        grid[i][j] = 1;

        const short directions = 4;
        const short x[directions] = { 1, -1, 0, 0 };
        const short y[directions] = { 0, 0, 1, -1 };
        for (short k = 0; k < directions; k++) {
            dfs(i + x[k], j + y[k], grid);
        }
    }
};