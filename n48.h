//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N48_H
#define LEETCODE2023_N48_H
#include "global.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int mid;
        for (int i = 0; i < matrix.size() / 2; ++i) {
            for (int j = 0; j < matrix.size() - i * 2 - 1; ++j) {
                mid = matrix[i][i + j];
                matrix[i][i + j] = matrix[matrix.size() - i - j - 1][i];
                matrix[matrix.size() - i - j - 1][i] = matrix[matrix.size() - i - 1][matrix.size() - i - j - 1];
                matrix[matrix.size() - i - 1][matrix.size() - i - j - 1] = matrix[i + j][matrix.size() - i - 1];
                matrix[i + j][matrix.size() - i - 1] = mid;
            }
        }
    }
};
#endif //LEETCODE2023_N48_H
