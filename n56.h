//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N56_H
#define LEETCODE2023_N56_H
#include "global.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2) {
            return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
        });
        vector<vector<int>> res;
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > right) {
                res.emplace_back(vector<int>{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else
                right = max(right, intervals[i][1]);
        }
        res.emplace_back(vector<int>{left, right});
        return res;
    }
};
#endif //LEETCODE2023_N56_H
