//
// Created by 58253 on 2023/7/14.
//

#ifndef LEETCODE2023_N560_H
#define LEETCODE2023_N560_H
#include "global.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0;
        int sum = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};
#endif //LEETCODE2023_N560_H
