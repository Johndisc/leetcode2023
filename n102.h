//
// Created by 58253 on 2023/7/16.
//

#ifndef LEETCODE2023_N102_H
#define LEETCODE2023_N102_H
#include "global.h"

class Solution {
public:
    vector<vector<int>> res;

    void fun(TreeNode *root, int level) {
        if (!root)
            return;
        if (res.size() <= level)
            res.emplace_back();
        res[level].push_back(root->val);
        fun(root->left, level + 1);
        fun(root->right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        fun(root, 0);
        return res;
    }
};
#endif //LEETCODE2023_N102_H
