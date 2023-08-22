//
// Created by 蒋子涵 on 2023/8/23.
//

#ifndef LEETCODE2023_N236_H
#define LEETCODE2023_N236_H
#include "global.h"

class Solution {
public:
    TreeNode *res;

    int dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || res)
            return 0;
        int num = 0;
        if (root == p || root == q)
            num++;
        num += dfs(root->left, p, q);
        num += dfs(root->right, p, q);
        if (res)
            return 0;
        if (num == 2)
            res = root;
        return num;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
};
#endif //LEETCODE2023_N236_H
