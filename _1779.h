#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDist = INT_MAX;
        int index = -1;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int dist = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (minDist > dist) {
                    index = i;
                    minDist = dist;
                }
            }
        }
        return index;
    }
};