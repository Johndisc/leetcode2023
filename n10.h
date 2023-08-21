//
// Created by 蒋子涵 on 2023/8/6.
//

#ifndef LEETCODE2023_N10_H
#define LEETCODE2023_N10_H
#include "global.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));
        dp[0][0] = true;
        int i, j;
        for (i = 1; i <= p.size(); i++) {
            if (p[i - 1] == '*')
                dp[i][0] = dp[i - 2][0];
            else
                dp[i][0] = false;
        }
        for (j = 1; j <= s.size(); j++) {
            dp[0][j] = false;
        }
        for (i = 1; i <= p.size(); ++i) {
            if (p[i - 1] == '.') {
                for (j = 1; j <= s.size(); j++) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            } else if (p[i - 1] == '*') {
                for (j = 1; j <= s.size(); ++j) {
                    if (p[i - 2] == '.' || s[j - 1] == p[i - 2])
                        dp[i][j] = dp[i][j - 1] || dp[i - 2][j];
                    else
                        dp[i][j] = dp[i - 2][j];
                }
            } else {
                for (j = 1; j <= s.size(); j++) {
                    dp[i][j] = p[i - 1] == s[j - 1] && dp[i - 1][j - 1];
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};
#endif //LEETCODE2023_N10_H
