//
// Created by 蒋子涵 on 2023/10/8.
//

#ifndef LEETCODE2023_N106_H
#define LEETCODE2023_N106_H
#include "global.h"

class Solution {
public:
	TreeNode *buildNode(vector<int> &inorder, int ins, int ine, vector<int> &postorder, int pos, int poe) {
		if (ins == ine)
			return nullptr;
		int root_val = postorder[poe - 1];
		int i = ins;
		for (; i < ine; i++) {
			if (inorder[i] == root_val) {
				break;
			}
		}

		TreeNode *node = new TreeNode(root_val);
		node->left = buildNode(inorder, ins, i, postorder, pos, pos + i - ins);
		node->right = buildNode(inorder, i + 1, ine, postorder, pos + i - ins, poe - 1);
		return node;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildNode(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}
};
#endif //LEETCODE2023_N106_H
