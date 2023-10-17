//
// Created by 蒋子涵 on 2023/8/23.
//

#ifndef LEETCODE2023_N74_H
#define LEETCODE2023_N74_H
#include "global.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = 0, e = matrix.size() - 1, mid;
        while (s <= e) {
            mid = (s + e) / 2;
            if (target >= matrix[mid][0] && (mid == e || target < matrix[mid + 1][0]))
                break;
            else if (target < matrix[mid][0])
                e = mid - 1;
            else
                s = mid + 1;
        }
        s = 0;
        e = matrix[0].size() - 1;
        while (s <= e) {
            int nmid = (s + e) / 2;
            if (target == matrix[mid][nmid]) {
                return true;
            }
            else if (target < matrix[mid][nmid]) {
                e = nmid - 1;
            }
            else
                s = nmid + 1;
        }
        return false;
    }
};
#endif //LEETCODE2023_N74_H
