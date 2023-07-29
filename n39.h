//
// Created by 蒋子涵 on 2023/7/28.
//

#ifndef LEETCODE2023_N39_H
#define LEETCODE2023_N39_H
#include "global.h"

class Solution {
public:
    vector<vector<int>> res;

    void solve(vector<int> &candidates, vector<int> &cur, int cur_sum, int target, int s) {
        if (s == candidates.size()) {
            if (cur_sum == target)
                res.push_back(cur);
            return;
        }
        for (int i = s; i < candidates.size(); ++i) {
            if (cur_sum + candidates[i] <= target) {
                cur.push_back(candidates[i]);
                solve(candidates, cur, cur_sum + candidates[i], target, i);
                cur.pop_back();
            } else {
                solve(candidates, cur, cur_sum, target, i + 1);
                break;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        solve(candidates, cur, 0, target, 0);
        return res;
    }
};
#endif //LEETCODE2023_N39_H
