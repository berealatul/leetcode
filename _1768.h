#pragma once
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int len1 = word1.length();
        int len2 = word2.length();
        string answer;
        while (i < len1 && i < len2) {
            answer += word1[i];
            answer += word2[i++];
        }

        if (i < len1) answer += word1.substr(i);
        if (i < len2) answer += word2.substr(i);
        return answer;
    }
};