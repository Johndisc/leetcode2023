//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N240_H
#define LEETCODE2023_N240_H
#include "global.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int s = 0, e = n - 1;
        while (s < m && e >= 0) {
            if (matrix[s][e] == target)
                return true;
            else if (matrix[s][e] < target)
                s++;
            else
                e--;
        }
        return false;
    }
};
#endif //LEETCODE2023_N240_H
