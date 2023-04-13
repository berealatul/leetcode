#pragma once
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> buffer;
        int j = 0, N = pushed.size();
        for (auto& val : pushed) {
            buffer.push(val);
            while (!buffer.empty() && j < N && buffer.top() == popped[j]) {
                buffer.pop();
                j++;
            }
        }
        return j == N;
    }
};