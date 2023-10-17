//
// Created by 蒋子涵 on 2023/9/6.
//

#ifndef LEETCODE2023_N1123_H
#define LEETCODE2023_N1123_H
#include "global.h"

class Solution {
public:
	TreeNode *res;
	int maxlen = 0;

	int dfs(TreeNode *root, int depth) {
		if (!root)
			return depth - 1;
		int left = dfs(root->left, depth + 1);
		int rihgt = dfs(root->right, depth + 1);
		if (left != rihgt)
			return max(left, rihgt);
		else {
			if (left >= maxlen) {
				maxlen = left;
				res = root;
			}
			return left;
		}
	}

	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		dfs(root, 0);
		return res;
	}
};
#endif //LEETCODE2023_N1123_H
