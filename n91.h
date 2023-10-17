//
// Created by 蒋子涵 on 2023/9/12.
//

#ifndef LEETCODE2023_N91_H
#define LEETCODE2023_N91_H
#include "global.h"

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		vector<int> dp(s.size() + 1, 0);
		dp[0] = 1;
		if (s[0] != '0')
			dp[1] = 1;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] != '0')
				dp[i + 1] = dp[i];
			if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
				dp[i + 1] += dp[i - 1];
		}
		return dp[s.size()];
	}
};
#endif //LEETCODE2023_N91_H
