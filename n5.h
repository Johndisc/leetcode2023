//
// Created by 58253 on 2023/7/22.
//

#ifndef LEETCODE2023_N5_H
#define LEETCODE2023_N5_H
#include "global.h"

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size() + 1, false));
        for (int i = 0; i < s.size(); ++i) {
            dp[i][0] = true;
            dp[i][1] = true;
        }
        string res;
        for (int i = 2; i <= s.size(); ++i) {
            for (int j = 0; j <= s.size() - i; ++j) {
                dp[j][i] = s[j] == s[j + i - 1] && dp[j + 1][i - 2];
                if (dp[j][i])
                    res = s.substr(j, i);
            }
        }
        for (int i = s.size(); i > 0; --i) {
            for (int j = 0; j <= s.size() - i; ++j) {
                if (dp[j][i]) {
                    return s.substr(j, i);
                }
            }
        }
        return res;
    }
};
#endif //LEETCODE2023_N5_H
