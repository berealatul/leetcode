#pragma once
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_t;
        unordered_map<char, char> t_s;

        for (int i = 0, n = s.size(); i < n; i++) {
            if (s_t.find(s[i]) == s_t.end() && t_s.find(t[i]) == t_s.end()) {
                s_t[s[i]] = t[i];
                t_s[t[i]] = s[i];
            }
            else if (s_t.find(s[i]) != s_t.end() && s_t[s[i]] != t[i]) return false;
            else if (t_s.find(t[i]) != t_s.end() && t_s[t[i]] != s[i]) return false;
        }
        return true;
        
    }
};