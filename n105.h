//
// Created by 蒋子涵 on 2023/8/21.
//

#ifndef LEETCODE2023_N105_H
#define LEETCODE2023_N105_H
#include "global.h"

class Solution {
public:
    TreeNode *solve(vector<int> &preorder, int s1, int e1, vector<int> &inorder, int s2, int e2) {
        if (s1 == preorder.size() || s1 == e1)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[s1]);
        if (s1 + 1 == e1)
            return root;
        for (int i = 0; i < e2 - s2; ++i) {
            if (inorder[s2 + i] == preorder[s1]) {
                root->left = solve(preorder, s1 + 1, s1 + i + 1, inorder, s2, s2 + i);
                root->right = solve(preorder, s1 + i + 1, e1, inorder, s2 + i + 1, e2);
            }
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
#endif //LEETCODE2023_N105_H
