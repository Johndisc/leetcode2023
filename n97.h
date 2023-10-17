//
// Created by 蒋子涵 on 2023/9/22.
//

#ifndef LEETCODE2023_N97_H
#define LEETCODE2023_N97_H
#include "global.h"

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())
			return false;
		vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		dp[0][0] = true;
		for (int i = 0; i < s1.size(); ++i) {
			if (s3[i] == s1[i])
				dp[i + 1][0] = true;
			else
				break;
		}
		for (int i = 0; i < s2.size(); ++i) {
			if (s3[i] == s2[i])
				dp[0][i + 1] = true;
			else
				break;
		}
		for (int i = 0; i < s1.size(); ++i) {
			for (int j = 0; j < s2.size(); ++j) {
				if (s1[i] == s3[i + j + 1])
					dp[i + 1][j + 1] = dp[i][j + 1];
				if (s2[j] == s3[i + j + 1] && !dp[i + 1][j + 1])
					dp[i + 1][j + 1] = dp[i + 1][j];
			}
		}
		return dp[s1.size()][s2.size()];
	}
};
#endif //LEETCODE2023_N97_H
