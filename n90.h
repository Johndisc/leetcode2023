//
// Created by 蒋子涵 on 2023/9/12.
//

#ifndef LEETCODE2023_N90_H
#define LEETCODE2023_N90_H
#include "global.h"

class Solution {
public:
	vector<vector<int>> res;

	void dfs(vector<int> &nums, vector<int> &cur, int start) {
		res.push_back(cur);
		int pre = -20;
		for (int i = start; i < nums.size(); ++i) {
			if (nums[i] != pre) {
				cur.push_back(nums[i]);
				dfs(nums, cur, i + 1);
				cur.pop_back();
				pre = nums[i];
			}
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<int> cur;
		sort(nums.begin(), nums.end());
		dfs(nums, cur, 0);
		return res;
	}
};
#endif //LEETCODE2023_N90_H
