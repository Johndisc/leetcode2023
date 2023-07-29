//
// Created by 蒋子涵 on 2023/7/28.
//

#ifndef LEETCODE2023_N46_H
#define LEETCODE2023_N46_H
#include "global.h"

class Solution {
public:
    vector<vector<int>> res;

    void findRes(vector<int> &nums, vector<int> &cur, vector<bool> &bitmap) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (bitmap[i]) {
                bitmap[i] = false;
                cur.push_back(nums[i]);
                findRes(nums, cur, bitmap);
                bitmap[i] = true;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<bool> bitmap(nums.size(), true);
        findRes(nums, cur, bitmap);
        return res;
    }
};
#endif //LEETCODE2023_N46_H
