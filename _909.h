#pragma once
#include <vector>
#include "myFunction.h"
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int, int> jump;
        findJump(board, jump);
        return bfs(board, jump);
    }
private:
    int bfs(vector<vector<int>>& board, unordered_map<int, int> jump) {
        int totalCells = pow(board.size(), 2);
        
        vector<bool> visited(totalCells + 1, false); // since number are from 1
        queue<int> elements;
        elements.push(1);
        visited[1] = true;

        int moves = 0;

        while (!elements.empty()) {
            int size = elements.size();

            while (size--) {
                auto current = elements.front();
                elements.pop();

                for (int dice = 1; dice <= 6; dice++) {
                    if (current + dice <= totalCells && !visited[current + dice]) {
                        if (current + dice == totalCells) return moves + 1;

                        if (!jump[current + dice]) {
                            visited[current + dice] = true;
                            elements.push(current + dice);
                        }
                        
                        if (jump[current + dice] && !visited[jump[current + dice]]) {
                            if (jump[current + dice] == totalCells) return moves + 1;

                            visited[jump[current + dice]] = true;
                            elements.push(jump[current + dice]);
                        }                        
                    }
                }
            }
            moves++;
        }

        return -1;
    }

    void findJump(vector<vector<int>>& board, unordered_map<int, int>& jump) {
        int n = board.size();
        bool goRight = true;
        int cell = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (goRight) {
                goRight = false;
                for (int j = 0; j < n; j++) {
                    if (board[i][j] != -1) jump[cell] = board[i][j];
                    cell++;
                    
                }
            }
            else {
                goRight = true;
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] != -1) jump[cell] = board[i][j];
                    cell++;
                }
            }
        }
    }
};