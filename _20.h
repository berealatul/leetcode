#pragma once
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> buffer;
        for (auto& val : s) {
            if (val == '(' || val == '{' || val == '[') {
                buffer.push(val);
                continue;
            }

            if (buffer.empty() ||
                val == ')' && buffer.top() != '(' ||
                val == '}' && buffer.top() != '{' ||
                val == ']' && buffer.top() != '[') return false;
            buffer.pop();
        }
        return buffer.empty();
    }
};