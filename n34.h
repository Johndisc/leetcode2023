//
// Created by 蒋子涵 on 2023/8/23.
//

#ifndef LEETCODE2023_N34_H
#define LEETCODE2023_N34_H
#include "global.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) {
                int x = mid, y = mid;
                while (x >= 0 && nums[x] == target)
                    x--;
                while (y < nums.size() && nums[y] == target)
                    y++;
                if (x < 0 || nums[x] != target)
                    x++;
                if (y == nums.size() || nums[y] != target)
                    y--;
                return vector<int>{x, y};
            }
            else if (nums[mid] > target) {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return vector<int>{-1, -1};
    }
};
#endif //LEETCODE2023_N34_H
