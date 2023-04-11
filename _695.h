#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxIsland = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    maxIsland = max(maxIsland, dfs(grid, i, j));
                }
            }
        }
        return maxIsland;
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j]) return 0;

        grid[i][j] = 0;
        int area = 1;

        const int direction = 4;
        int x[direction] = { 1, -1, 0, 0 };
        int y[direction] = { 0, 0, 1, -1 };
        for (int k = 0; k < direction; k++) {
            area += dfs(grid, i + x[k], j + y[k]);
        }
        return area;
    }
};
