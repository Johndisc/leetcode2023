//
// Created by 58253 on 2023/7/16.
//

#ifndef LEETCODE2023_N98_H
#define LEETCODE2023_N98_H
#include "global.h"

class Solution {
public:
    pair<bool, pair<int, int>> fun(TreeNode *root) {
        int mi = root->val, ma = root->val;
        if (root->left) {
            auto lr = fun(root->left);
            if (!lr.first || lr.second.second >= root->val)
                return make_pair(false, make_pair(mi, ma));
            mi = min(mi, lr.second.first);
            ma = max(ma, lr.second.second);
        }
        if (root->right) {
            auto rr = fun(root->right);
            if (!rr.first || rr.second.first <= root->val)
                return make_pair(false, make_pair(mi, ma));
            mi = min(mi, rr.second.first);
            ma = max(ma, rr.second.second);
        }
        return make_pair(true, make_pair(mi, ma));
    }

    bool isValidBST(TreeNode* root) {
        auto res = fun(root);
        return res.first;
    }
};
#endif //LEETCODE2023_N98_H
