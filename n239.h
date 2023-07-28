//
// Created by 58253 on 2023/7/14.
//

#ifndef LEETCODE2023_N239_H
#define LEETCODE2023_N239_H
#include "global.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[i] > dq.back())
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        res.push_back(dq.front());
        for (int i = 0; i < nums.size() - k; ++i) {
            if (nums[i] == dq.front())
                dq.pop_front();
            while (!dq.empty() && nums[i + k] > dq.back())
                dq.pop_back();
            dq.push_back(nums[i + k]);
            res.push_back(dq.front());
        }
        return res;
    }
};
#endif //LEETCODE2023_N239_H
