#pragma once
#include <vector>
#include <queue>
#include "myFunction.h"
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // build graph
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        visited.resize(n, 0);
        return dfs(graph, source, destination);
    }
private:
    vector<int> visited;

    bool bfs(vector<vector<int>>& graph, int source, int destination) {
        queue<int> elements;
        elements.push(source);
        visited[source] = 1;

        while (!elements.empty()) {
            auto current = elements.front();
            elements.pop();

            if (current == destination) return true;

            for (auto& val : graph[current]) {
                if (!visited[val]) {
                    elements.push(val);
                    visited[val] = 1;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<int>>& graph, int current, int destination) {
        if (current == destination) return true;
        if (visited[current]) return false;

        visited[current] = 1;

        for (auto& val : graph[current]) {
            if(dfs(graph, val, destination)) return true;
        }
        return false;
    }
};