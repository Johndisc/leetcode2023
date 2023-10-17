//
// Created by 蒋子涵 on 2023/9/22.
//

#ifndef LEETCODE2023_N96_H
#define LEETCODE2023_N96_H
#include "global.h"

class Solution {
public:
	int numTrees(int n) {
		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 1));
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j <= n - i; ++j) {
				dp[j][j + i] = 0;
				for (int k = j; k <= j + i; ++k) {
					dp[j][j + i] += dp[j][k - 1] * dp[k + 1][j + i];
				}
			}
		}
		return dp[1][n];
	}
};
#endif //LEETCODE2023_N96_H
