//
// Created by 58253 on 2023/7/22.
//

#ifndef LEETCODE2023_N32_H
#define LEETCODE2023_N32_H
#include "global.h"

class Solution {
public:
    int longestValidParentheses(string s) {
		int res = 0;
		vector<int> dp(s.size() + 2, 0);
		dp[0] = 0;
		dp[1] = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '(')
				dp[i + 1] = 0;
			else {
				if (s[i - 1] == '(')
					dp[i + 1] = dp[i - 1] + 2;
				else if (i - dp[i] - 1 >= 0 && s[i - dp[i] - 1] == '(')
					dp[i + 1] = dp[i - dp[i] - 1] + dp[i] + 2;
				else
					dp[i + 1] = 0;
				res = max(res, dp[i + 1]);
			}
        }
		return res;
    }
};
#endif //LEETCODE2023_N32_H
