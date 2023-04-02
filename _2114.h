#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution {
    int countWords(string& sentence) {
        int wordCount = (sentence.empty()) ? 0 : 1;

        for (auto& character : sentence) {
            if (character == ' ') wordCount++;
        }

        return wordCount;
    }

public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;

        for (auto& sentence : sentences) {
            maxWords = max(maxWords, countWords(sentence));
        }

        return maxWords;
    }
};