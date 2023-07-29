//
// Created by 蒋子涵 on 2023/7/28.
//

#ifndef LEETCODE2023_N78_H
#define LEETCODE2023_N78_H
#include "global.h"

class Solution {
public:
    vector<vector<int>> res;

    void solve(vector<int> &nums, vector<int> &cur, int s) {
        if (s == nums.size()) {
            res.push_back(cur);
            return;
        }
        solve(nums, cur, s + 1);
        cur.push_back(nums[s]);
        solve(nums, cur, s + 1);
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        solve(nums, cur, 0);
        return res;
    }
};
#endif //LEETCODE2023_N78_H
