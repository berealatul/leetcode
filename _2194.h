#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        string columnStart, columnEnd;
        int rowStart, rowEnd;
        getRange(s, columnStart, columnEnd, rowStart, rowEnd);

        
        int lastColumn = getColumnNumberTitle(columnEnd);
        int currentColumn = getColumnNumberTitle(columnStart);
        
        vector<string> list;
        while (currentColumn <= lastColumn) {

            for (int i = rowStart; i <= rowEnd; i++) {
                list.push_back(columnStart + to_string(i));
            }

            columnStart = findNextColumn(columnStart);
            currentColumn = getColumnNumberTitle(columnStart);
        }

        return list;
    }



private:
    void getRange(string& s, string& columnStart, string& columnEnd, int& rowStart, int& rowEnd) {
        int index = 0;
        while (isalpha(s[index])) columnStart += s[index++];

        string temp;
        while (isalnum(s[index])) temp = s[index++];
        rowStart = stoi(temp);

        index++;
        while (isalpha(s[index])) columnEnd += s[index++];

        temp = "";
        while (isalnum(s[index]) && index < s.length()) temp = s[index++];
        rowEnd = stoi(temp);
    }

    string findNextColumn(string& current) {
        return findNextColumn(current, current.length() - 1);
    }

    string findNextColumn(string& current, int last) {
        if (last < 0) {
            current = 'A' + current;
            return current;
        }

        if (current[last] < 'Z') {
            current[last] = (current[last] + 1);
            return current;
        }

        current[last] = 'A';

        return findNextColumn(current, last - 1);
    }

    int getColumnNumberTitle(string& previous) {
        int columnNumber = 0;

        for (int i = 0, n = previous.length() - 1; i <= n; i++) {
            columnNumber += pow(26, n - i) * (previous[i] - 64);
        }

        return columnNumber;
    }
};