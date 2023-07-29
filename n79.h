//
// Created by 58253 on 2023/7/29.
//

#ifndef LEETCODE2023_N79_H
#define LEETCODE2023_N79_H
#include "global.h"

class Solution {
public:
    bool res = false;

    bool solve(vector<vector<char>> &board, vector<vector<bool>> &bitmap, string &word, int pos, int i, int j) {
        if (pos == word.size()) {
            res = true;
            return true;
        }
        if (i > 0 && bitmap[i - 1][j] && board[i - 1][j] == word[pos]) {
            bitmap[i - 1][j] = false;
            if (solve(board, bitmap, word, pos + 1, i - 1, j))
                return true;
            bitmap[i - 1][j] = true;
        }
        if (i < board.size() - 1 && bitmap[i + 1][j] && board[i + 1][j] == word[pos]) {
            bitmap[i + 1][j] = false;
            if (solve(board, bitmap, word, pos + 1, i + 1, j))
                return true;
            bitmap[i + 1][j] = true;
        }
        if (j > 0 && bitmap[i][j - 1] && board[i][j - 1] == word[pos]) {
            bitmap[i][j - 1] = false;
            if (solve(board, bitmap, word, pos + 1, i, j - 1))
                return true;
            bitmap[i][j - 1] = true;
        }
        if (j < board[0].size() - 1 && bitmap[i][j + 1] && board[i][j + 1] == word[pos]) {
            bitmap[i][j + 1] = false;
            if (solve(board, bitmap, word, pos + 1, i, j + 1))
                return true;
            bitmap[i][j + 1] = true;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> bitmap(board.size(), vector<bool>(board[0].size(), true));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    bitmap[i][j] = false;
                    if (solve(board, bitmap, word, 1, i, j))
                        return true;
                    bitmap[i][j] = true;
                }
            }
        }
        return false;
    }
};
#endif //LEETCODE2023_N79_H
