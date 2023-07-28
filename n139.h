//
// Created by 58253 on 2023/7/16.
//

#ifndef LEETCODE2023_N139_H
#define LEETCODE2023_N139_H
#include "global.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            string sub;
            for (int j = i; j < s.size(); ++j) {
                sub.append(1, s[j]);
                if (wordSet.count(sub)) {
                    dp[i] = dp[j + 1];
                    if (dp[i])
                        break;
                }
            }
        }
        return dp[0];
    }
};
#endif //LEETCODE2023_N139_H
