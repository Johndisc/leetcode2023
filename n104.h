//
// Created by 蒋子涵 on 2023/8/5.
//

#ifndef LEETCODE2023_N104_H
#define LEETCODE2023_N104_H
#include "global.h"

class Solution {
public:
    int res;

    void solve(TreeNode *root, int depth) {
        if (!root) {
            res = max(res, depth);
            return;
        }
        solve(root->left, depth + 1);
        solve(root->right, depth + 1);
    }
    int maxDepth(TreeNode* root) {
        res = 0;
        solve(root, 0);
        return res;
    }
};
#endif //LEETCODE2023_N104_H
