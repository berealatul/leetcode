#pragma once
#include <iostream>
#include <sstream>
#include "myFunction.h"
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {        
        vector<string> block;
        string buffer;
        for (stringstream ss(path); getline(ss, buffer, '/'); ) {
            block.push_back(buffer);
        }

        vector<string> pile;

        for (auto& val : block) {
            if (!pile.empty() && val == "..") pile.pop_back();

            if (val != "" && val != "." && val != "..") pile.push_back(val);
        }

        if (pile.empty()) return "/";
        buffer = "";
        for (auto& val : pile) buffer += "/" + val;

        return buffer;
    }
};
