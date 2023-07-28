//
// Created by 58253 on 2023/7/16.
//

#ifndef LEETCODE2023_N994_H
#define LEETCODE2023_N994_H
#include "global.h"

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        bool finished = false;
        int minute = -1;
        while (!finished) {
            minute++;
            finished = true;
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    if (grid[i][j] == 2) {
                        if (i > 0 && grid[i - 1][j] == 1) {
                            grid[i - 1][j] = -2;
                            finished = false;
                        }
                        if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
                            grid[i + 1][j] = -2;
                            finished = false;
                        }
                        if (j > 0 && grid[i][j - 1] == 1) {
                            grid[i][j - 1] = -2;
                            finished = false;
                        }
                        if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {
                            grid[i][j + 1] = -2;
                            finished = false;
                        }
                    }
                }
            }
            for (int i = 0; i < grid.size(); ++i)
                for (int j = 0; j < grid[0].size(); ++j)
                    if (grid[i][j] == -2)
                        grid[i][j] = 2;
        }
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1)
                    return -1;

        return minute;
    }
};
#endif //LEETCODE2023_N994_H
