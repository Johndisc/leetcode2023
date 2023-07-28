//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N238_H
#define LEETCODE2023_N238_H
#include "global.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
            res[i] = res[i - 1] * nums[i - 1];

        int mul = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= mul;
            mul *= nums[i];
        }
        return res;
    }
};
#endif //LEETCODE2023_N238_H
