//
// Created by 58253 on 2023/7/16.
//

#ifndef LEETCODE2023_N322_H
#define LEETCODE2023_N322_H
#include "global.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i:coins)
            if (i <= amount)
                dp[i] = 1;
        for (int i = 1; i <= amount; ++i) {
            if (dp[i] != INT_MAX)
                continue;
            for (int j: coins) {
                if (i > j && dp[i-j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - j] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
#endif //LEETCODE2023_N322_H
