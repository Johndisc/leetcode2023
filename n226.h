//
// Created by 蒋子涵 on 2023/8/5.
//

#ifndef LEETCODE2023_N226_H
#define LEETCODE2023_N226_H
#include "global.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;
        TreeNode *mid = root->left;
        root->left = root->right;
        root->right = mid;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
#endif //LEETCODE2023_N226_H
