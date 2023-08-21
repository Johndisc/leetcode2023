//
// Created by 蒋子涵 on 2023/8/19.
//

#ifndef LEETCODE2023_N108_H
#define LEETCODE2023_N108_H
#include "global.h"

class Solution {
public:
    TreeNode *sortedArray(vector<int> &nums, int s, int e) {
        if (s >= e) {
            return nullptr;
        }
        int mid = (s + e) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = sortedArray(nums, s, mid);
        node->right = sortedArray(nums, mid + 1, e);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArray(nums, 0, nums.size());
    }
};
#endif //LEETCODE2023_N108_H
