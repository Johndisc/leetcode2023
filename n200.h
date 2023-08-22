//
// Created by 蒋子涵 on 2023/8/23.
//

#ifndef LEETCODE2023_N200_H
#define LEETCODE2023_N200_H
#include "global.h"

class Solution {
public:
    int res = 0;

    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i > 0 && grid[i - 1][j] == '1') {
            grid[i - 1][j] = '0';
            dfs(grid, i - 1, j);
        }
        if (i < grid.size() - 1 && grid[i + 1][j] == '1') {
            grid[i + 1][j] = '0';
            dfs(grid, i + 1, j);
        }
        if (j > 0 && grid[i][j - 1] == '1') {
            grid[i][j - 1] = '0';
            dfs(grid, i, j - 1);
        }
        if (j < grid[0].size() - 1 && grid[i][j + 1] == '1') {
            grid[i][j + 1] = '0';
            dfs(grid, i, j + 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
#endif //LEETCODE2023_N200_H
