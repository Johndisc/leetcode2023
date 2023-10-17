//
// Created by 蒋子涵 on 2023/9/6.
//

#ifndef LEETCODE2023_N47_H
#define LEETCODE2023_N47_H
#include "global.h"

class Solution {
public:
	vector<vector<int>> res;

	void solve(vector<int> &nums, vector<int> cur, vector<bool> &bitmap) {
		if (cur.size() == nums.size()) {
			res.push_back(cur);
			return;
		}
		int pre = 11;
		for (int j = 0; j < nums.size(); ++j) {
			if (bitmap[j] && nums[j] != pre) {
				cur.push_back(nums[j]);
				bitmap[j] = false;
				solve(nums, cur, bitmap);
				cur.pop_back();
				bitmap[j] = true;
				pre = nums[j];
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> cur;
		vector<bool> bitmap(nums.size(), true);
		solve(nums, cur, bitmap);
		return res;
	}
};
#endif //LEETCODE2023_N47_H
