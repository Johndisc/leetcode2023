//
// Created by 58253 on 2023/7/5.
//

#ifndef LEETCODE2023_N1_H
#define LEETCODE2023_N1_H

#include "global.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                res[0] = i;
                res[1] = m[target - nums[i]];
                break;
            }
            else
                m[nums[i]] = i;
        }
        return res;
    }
};

#endif //LEETCODE2023_N1_H
