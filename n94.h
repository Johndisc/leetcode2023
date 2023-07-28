//
// Created by 58253 on 2023/7/16.
//

#ifndef LEETCODE2023_N94_H
#define LEETCODE2023_N94_H
#include "global.h"

class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return res;
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }
};
#endif //LEETCODE2023_N94_H
