//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N189_H
#define LEETCODE2023_N189_H
#include "global.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
#endif //LEETCODE2023_N189_H
