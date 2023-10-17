//
// Created by 蒋子涵 on 2023/10/8.
//

#ifndef LEETCODE2023_N103_H
#define LEETCODE2023_N103_H
#include "global.h"

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)
			return res;
		vector<TreeNode*> pre, next;
		vector<int> cur;
		pre.push_back(root);
		cur.push_back(root->val);
		res.push_back(cur);
		int level = 1;
		while (!pre.empty()) {
			if (level % 2) {
				for (auto it = pre.rbegin(); it != pre.rend(); it++) {
					if ((*it)->right)
						next.push_back((*it)->right);
					if ((*it)->left)
						next.push_back((*it)->left);
				}
			}
			else {
				for (auto it = pre.rbegin(); it != pre.rend(); it++) {
					if ((*it)->left)
						next.push_back((*it)->left);
					if ((*it)->right)
						next.push_back((*it)->right);
				}
			}
			cur.clear();
			for (auto it: next) {
				cur.push_back(it->val);
			}
			if (!cur.empty())
				res.push_back(cur);
			pre = next;
			next.clear();
			level++;
		}
		return res;
	}
};
#endif //LEETCODE2023_N103_H
