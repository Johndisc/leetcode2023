//
// Created by 蒋子涵 on 2023/9/22.
//

#ifndef LEETCODE2023_N95_H
#define LEETCODE2023_N95_H
#include "global.h"

class Solution {
public:
	vector<TreeNode *> dfs(int start, int end) {
		vector<TreeNode *> res;
		if (start > end) {
			res.push_back(nullptr);
			return res;
		}
		for (int i = start; i <= end; i++) {
			auto left = dfs(start, i - 1);
			auto right = dfs(i + 1, end);
			for (auto ln: left) {
				for (auto rn: right) {
					auto *node = new TreeNode;
					node->val = i;
					node->left = ln;
					node->right = rn;
					res.push_back(node);
				}
			}
		}
		return res;
	}

	vector<TreeNode*> generateTrees(int n) {
		return dfs(1, n);
	}
};
#endif //LEETCODE2023_N95_H
