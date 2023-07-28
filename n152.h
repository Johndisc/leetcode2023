//
// Created by 58253 on 2023/7/21.
//

#ifndef LEETCODE2023_N152_H
#define LEETCODE2023_N152_H
#include "global.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxdp(nums.size(), 1);
        vector<int> mindp(nums.size(), 1);
        maxdp[0] = mindp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                maxdp[i] = max(1, max(maxdp[i - 1], mindp[i - 1])) * nums[i];
                mindp[i] = min(1, min(maxdp[i - 1], mindp[i - 1])) * nums[i];
                res = max(res, maxdp[i]);
            }
            else {
                maxdp[i] = min(1, min(maxdp[i - 1], mindp[i - 1])) * nums[i];
                mindp[i] = max(1, max(maxdp[i - 1], mindp[i - 1])) * nums[i];
                res = max(res, maxdp[i]);
            }
        }
        return res;
    }
};
#endif //LEETCODE2023_N152_H
