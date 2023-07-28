//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N73_H
#define LEETCODE2023_N73_H
#include "global.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> rows(matrix.size(), false);
        vector<bool> cols(matrix[0].size(), false);

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            if (rows[i]) {
                for (int j = 0; j < matrix[0].size(); ++j)
                    matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            if (cols[i]) {
                for (int j = 0; j < matrix.size(); ++j)
                    matrix[j][i] = 0;
            }
        }
    }
};
#endif //LEETCODE2023_N73_H
