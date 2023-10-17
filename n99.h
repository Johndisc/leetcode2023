//
// Created by 蒋子涵 on 2023/9/22.
//

#ifndef LEETCODE2023_N99_H
#define LEETCODE2023_N99_H
#include "global.h"

class Solution {
public:
	vector<pair<int, TreeNode *>> map;

	void dfs(TreeNode *root) {
		if (root->left)
			dfs(root->left);
		map.emplace_back(root->val, root);
		if (root->right)
			dfs(root->right);
	}

	void recoverTree(TreeNode* root) {
		dfs(root);
		TreeNode *n1, *n2;
		for (int i = 0; i < map.size() - 1; ++i) {
			if (map[i].first > map[i + 1].first) {
				n1 = map[i].second;
				break;
			}
		}
		for (int i = map.size() - 1; i > 0; --i) {
			if (map[i].first < map[i - 1].first) {
				n2 = map[i].second;
				break;
			}
		}
		swap(n1->val, n2->val);
	}
};
#endif //LEETCODE2023_N99_H
