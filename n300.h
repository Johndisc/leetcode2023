//
// Created by 58253 on 2023/7/21.
//

#ifndef LEETCODE2023_N300_H
#define LEETCODE2023_N300_H
#include "global.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};
#endif //LEETCODE2023_N300_H
