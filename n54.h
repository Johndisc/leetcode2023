//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N54_H
#define LEETCODE2023_N54_H
#include "global.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < (min(m, n) + 1) / 2; ++i) {
            res.push_back(matrix[i][i]);
            for (int j = i + 1; j <= n - i - 1; ++j)
                res.push_back(matrix[i][j]);
            int sz = res.size();
            for (int j = i + 1; j <= m - i - 1; ++j)
                res.push_back(matrix[j][n - 1 - i]);
            if (res.size() == sz)
                break;
            sz = res.size();
            for (int j = n - i - 2; j >= i; --j)
                res.push_back(matrix[m - i - 1][j]);
            if (res.size() == sz)
                break;
            sz = res.size();
            for (int j = m - i - 2; j > i; --j)
                res.push_back(matrix[j][i]);
        }

        return res;
    }
};
#endif //LEETCODE2023_N54_H
