//
// Created by 蒋子涵 on 2023/9/9.
//

#ifndef LEETCODE2023_N77_H
#define LEETCODE2023_N77_H
#include "global.h"

class Solution {
public:
	vector<vector<int>> res;

	void solve(vector<bool> &bitmap, vector<int> &cur, int k, int next) {
		if (cur.size() == k) {
			res.push_back(cur);
			return;
		}
		for (int i = next; i < bitmap.size(); ++i) {
			if (bitmap[i]) {
				cur.push_back(i);
				bitmap[i] = false;
				solve(bitmap, cur, k, i + 1);
				bitmap[i] = true;
				cur.pop_back();
			}
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<bool> bitmap(n + 1, true);
		vector<int> cur;
		solve(bitmap, cur, k, 1);
		return res;
	}
};
#endif //LEETCODE2023_N77_H
