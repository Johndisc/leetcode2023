//
// Created by 蒋子涵 on 2023/8/21.
//

#ifndef LEETCODE2023_N199_H
#define LEETCODE2023_N199_H
#include "global.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        int last = 1;
        while (!q.empty()) {
            int cur = 0;
            res.push_back(q.front()->val);
            for (int i = 0; i < last; ++i) {
                if (q.front()->right) {
                    q.push(q.front()->right);
                    cur++;
                }
                if (q.front()->left) {
                    q.push(q.front()->left);
                    cur++;
                }
                q.pop();
            }
            last = cur;
        }
        return res;
    }
};
#endif //LEETCODE2023_N199_H
