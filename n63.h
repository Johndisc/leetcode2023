//
// Created by 蒋子涵 on 2023/9/6.
//

#ifndef LEETCODE2023_N63_H
#define LEETCODE2023_N63_H
#include "global.h"

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
		for (int i = 0; i < dp.size(); ++i) {
			if (obstacleGrid[i][0] == 0)
				dp[i][0] = 1;
			else {
				dp[i][0] = 0;
				break;
			}
		}
		for (int i = 0; i < dp[0].size(); ++i) {
			if (obstacleGrid[0][i] == 0)
				dp[0][i] = 1;
			else {
				dp[0][i] = 0;
				break;
			}
		}
		for (int i = 1; i < dp.size(); ++i) {
			for (int j = 1; j < dp[0].size(); ++j) {
				if (obstacleGrid[i][j] == 1)
					continue;
				if (obstacleGrid[i - 1][j] == 0)
					dp[i][j] += dp[i - 1][j];
				if (obstacleGrid[i][j - 1] == 0)
					dp[i][j] += dp[i][j - 1];
			}
		}
		return dp[dp.size() - 1][dp[0].size() - 1];
	}
};
#endif //LEETCODE2023_N63_H
