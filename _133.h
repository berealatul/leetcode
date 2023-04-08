#pragma once
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// dfs solution
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if (copiedList.find(node) == copiedList.end()) {
            copiedList[node] = new Node(node->val);
            for (auto& neighbor : node->neighbors) {
                copiedList[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }

        return copiedList[node];
    }
private:
    unordered_map<Node*, Node*> copiedList;
};

// bfs solution (good for understanding)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> copiedList;
        Node* copyHead = new Node(node->val);
        copiedList[node] = copyHead;

        queue<Node*> list;
        list.push(node);

        while (!list.empty()) {
            auto currentNode = list.front();
            list.pop();

            for (auto& neighbor : currentNode->neighbors) {
                if (copiedList.find(neighbor) == copiedList.end()) {
                    copiedList[neighbor] = new Node(neighbor->val);
                    list.push(neighbor);
                }

                copiedList[currentNode]->neighbors.push_back(copiedList[neighbor]);
            }
        }

        return copyHead;
    }
};

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};