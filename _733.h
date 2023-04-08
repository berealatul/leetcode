#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        oldColor = image[sr][sc];
        newColor = color;
        if (oldColor == newColor) return image;

        dfs(sr, sc, image);

        return image;
    }
private:
    int oldColor, newColor;
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != oldColor) return;

        grid[i][j] = newColor;

        const short directions = 4;
        const short x[directions] = { 1, -1, 0, 0 };
        const short y[directions] = { 0, 0, 1, -1 };
        for (short k = 0; k < directions; k++) {
            dfs(i + x[k], j + y[k], grid);
        }
    }
};