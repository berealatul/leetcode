#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include  "myFunction.h"
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> zeroDegree;
        for (int i = 0; i < n; i++) if (!indegree[i]) zeroDegree.push(i);

        vector<vector<int>> colorCount(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) colorCount[i][colors[i] - 'a']++;

        int maxCount = 0;
        int visitedNodeCount = 0;
        while (!zeroDegree.empty()) {
            visitedNodeCount++;

            int node1 = zeroDegree.front();
            zeroDegree.pop();

            for (auto& node2 : graph[node1]) {
                for (int i = 0; i < colorCount[0].size(); i++) {
                    short temp = (colors[node2] - 'a' == i) ? 1 : 0;
                    
                    colorCount[node2][i] = max(colorCount[node2][i], colorCount[node1][i]+ temp);
                }

                if (!(--indegree[node2])) zeroDegree.push(node2);
            }

            maxCount = max(maxCount, *max_element(colorCount[node1].begin(), colorCount[node1].end()));
        }

        return (visitedNodeCount == n) ? maxCount : -1;
    }
};