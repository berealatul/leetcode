#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> answer;
        for (auto& word : words) {
            if (!multipleRowCharacter(toLower(word))) answer.push_back(word);
        }
        return answer;
    }

private:
    string firstRow = "qwertyuiop";
    string secondRow = "asdfghjkl";
    string thirdRow = "zxcvbnm";

    string toLower(string word) {
        for (int i = 0; i < word.length(); i++) word[i] = tolower(word[i]);
        return word;
    }

    bool multipleRowCharacter(string word) {
        return (
            (word.find_first_of(firstRow) != -1 && word.find_first_of(secondRow) != -1) ||
            (word.find_first_of(firstRow) != -1 && word.find_first_of(thirdRow) != -1) ||
            (word.find_first_of(secondRow) != -1 && word.find_first_of(thirdRow) != -1));
    }
};