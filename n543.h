//
// Created by 58253 on 2023/7/16.
//

#ifndef LEETCODE2023_N543_H
#define LEETCODE2023_N543_H
#include "global.h"

class Solution {
public:
    int res = 0;
    int fun(TreeNode* root) {
        if (!root)
            return 0;
        int left = fun(root->left);
        int right = fun(root->right);
        res = max(res, left + right + 1);
        cout << root->val << " " << left << " " << right << " " << res << endl;
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        fun(root);
        return res - 1;
    }
};
#endif //LEETCODE2023_N543_H
