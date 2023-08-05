//
// Created by 蒋子涵 on 2023/8/6.
//

#ifndef LEETCODE2023_N101_H
#define LEETCODE2023_N101_H
#include "global.h"

class Solution {
public:
    bool compare(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;
        if (!left||!right)
            return false;
        if (left->val != right->val)
            return false;
        return compare(left->left, right->right) && compare(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return compare(root->left, root->right);
    }
};
#endif //LEETCODE2023_N101_H
