//
// Created by 58253 on 2023/7/12.
//

#ifndef LEETCODE2023_N15_H
#define LEETCODE2023_N15_H
#include "global.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i;
        for (i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == 0) {
                    res.emplace_back(vector<int>{nums[i], nums[l], nums[r]});
                    do {
                        l++;
                    } while (l < r && nums[l - 1] == nums[l]);
                    do {
                        r--;
                    } while (l < r && nums[r + 1] == nums[r]);

                }
                else if (sum < 0)
                    l++;
                else
                    r--;
            }
        }
        return res;
    }
};
#endif //LEETCODE2023_N15_H
