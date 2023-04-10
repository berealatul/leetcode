#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;

        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
private:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int oldColor) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != oldColor) return;

        image[i][j] = newColor;

        const int direction = 4;
        int x[direction] = { 1, -1, 0, 0 };
        int y[direction] = { 0, 0, 1, -1 };
        for (int k = 0; k < direction; k++) {
            dfs(image, i + x[k], j + y[k], newColor, oldColor);
        }
    }
};