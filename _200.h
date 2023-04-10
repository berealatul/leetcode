#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1') return;

        grid[i][j] = '0';

        const int direction = 4;
        int x[direction] = { 1, -1, 0, 0 };
        int y[direction] = { 0, 0, 1, -1 };
        for (int k = 0; k < direction; k++) {
            dfs(grid, i + x[k], j + y[k]);
        }
    }
};