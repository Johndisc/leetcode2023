//
// Created by 蒋子涵 on 2023/8/21.
//

#ifndef LEETCODE2023_N114_H
#define LEETCODE2023_N114_H
#include "global.h"

class Solution {
public:
    TreeNode* solve(TreeNode *root) {
        if (!root->left && !root->right)
            return root;
        auto left = root;
        if (root->left) {
            left = solve(root->left);
            left->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        if (left->right)
            return solve(root->right);
        else
            return left;
    }

    void flatten(TreeNode* root) {
        if (!root)
            return;
        solve(root);
    }
};
#endif //LEETCODE2023_N114_H
