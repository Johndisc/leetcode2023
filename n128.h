//
// Created by 58253 on 2023/7/11.
//

#ifndef LEETCODE2023_N128_H
#define LEETCODE2023_N128_H
#include "global.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> visited(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int len = 0, mid = nums[i];
            while (visited.count(mid)) {
                visited.erase(mid);
                len++;
                mid++;
            }
            mid = nums[i] - 1;
            while (visited.count(mid)) {
                visited.erase(mid);
                len++;
                mid--;
            }
            res = max(res, len);
        }
        return res;
    }
};
#endif //LEETCODE2023_N128_H
