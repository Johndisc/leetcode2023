//
// Created by 蒋子涵 on 2023/8/29.
//

#ifndef LEETCODE2023_N215_H
#define LEETCODE2023_N215_H
#include "global.h"

class Solution {
public:
    void adjust(vector<int> &nums, int n, int index) {
        int mid = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < n && nums[mid] < nums[left]) {
            mid = left;
        }
        if (right < n && nums[mid] < nums[right]) {
            mid = right;
        }
        if (mid != index) {
            swap(nums[mid], nums[index]);
            adjust(nums, n, mid);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        for (int i = nums.size() - 1; i >= 0; --i) {
            adjust(nums, nums.size(), i);
        }

        for (int i = 0; i < k - 1; ++i) {
            swap(nums[0], nums[nums.size() - i - 1]);
            adjust(nums, nums.size() - i, 0);
        }
        return nums[0];
    }
};
#endif //LEETCODE2023_N215_H
