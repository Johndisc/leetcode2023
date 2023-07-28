//
// Created by 58253 on 2023/7/16.
//

#ifndef LEETCODE2023_N230_H
#define LEETCODE2023_N230_H
#include "global.h"

class Solution {
public:
    int cnt = 0;
    int res;

    void fun(TreeNode *root, int k) {
        if (root->left)
            fun(root->left, k);
        cnt++;
        if (cnt == k) {
            res = root->val;
            return;
        }
        if (root->right)
            fun(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        fun(root, k);
        return res;
    }
};
#endif //LEETCODE2023_N230_H
