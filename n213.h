//
// Created by 蒋子涵 on 2023/8/7.
//

#ifndef LEETCODE2023_N213_H
#define LEETCODE2023_N213_H
#include "global.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> dp1(nums.size(), 0), dp2(nums.size(), 0);
        dp2[0] = nums[0];
        dp1[1] = nums[1];
        dp2[1] = nums[0];
        for (int i = 2; i < nums.size() - 1; ++i) {
            dp1[i] = max(nums[i] + dp1[i - 2], dp1[i - 1]);
            dp2[i] = max(nums[i] + dp2[i - 2], dp2[i - 1]);
        }
        dp1[nums.size() - 1] = max(nums[nums.size() - 1] + dp1[nums.size() - 3], dp1[nums.size() - 2]);
        dp2[nums.size() - 1] = dp2[nums.size() - 2];
        return max(dp1[nums.size() - 1], dp2[nums.size() - 1]);
    }
};
#endif //LEETCODE2023_N213_H
