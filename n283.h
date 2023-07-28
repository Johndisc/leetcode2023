//
// Created by 58253 on 2023/7/11.
//

#ifndef LEETCODE2023_N283_H
#define LEETCODE2023_N283_H
#include "global.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0;
        while (fast < nums.size() && slow < nums.size()) {
            if (nums[slow] != 0)
                slow++;
            else if (fast <= slow)
                fast = slow + 1;
            else if (nums[fast] == 0)
                fast++;
            else {
                swap(nums[slow], nums[fast]);
                fast++;
                slow++;
            }
        }
    }
};

#endif //LEETCODE2023_N283_H
