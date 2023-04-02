#pragma once
#include <string>
using namespace std;

class Solution {
public:
    string interpret(string command) {

        for (int i = 0; i < command.length(); i++) {
            if (command[i] == '(') {
                if (command[i + 1] == ')') command.replace(i, 2, "o");                
                else command.replace(i, 4, "al");
            }
        }

        return command;
    }
};

class Solution {
public:
    string interpret(string command) {
        string word;
        for (int i = 0, n = command.length(); i < n; i++) {
            switch (command[i]) {
            case 'G':
                word += 'G';
                break;
            case '(':
                if (command[i + 1] == ')') word += 'o';
                else word += "al";
            }
        }

        return word;
    }
};