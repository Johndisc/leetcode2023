//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N53_H
#define LEETCODE2023_N53_H
#include "global.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
            res = max(res, dp[i]);
        }
        return res;
    }
};
#endif //LEETCODE2023_N53_H
