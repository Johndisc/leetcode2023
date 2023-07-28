//
// Created by 58253 on 2023/7/22.
//

#ifndef LEETCODE2023_N32_H
#define LEETCODE2023_N32_H
#include "global.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int balance = 0;
        int len = 0;
        int res = 0;
        int begin = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                balance--;
                len++;
                if (balance == 0)
                    res = max(res, len - balance);
                else if (balance > 0)
                    res = max(res, i - begin - balance);
            } else if (balance < 0) {
                begin = i;
                balance = 1;
                len = 1;
            } else {
                if (balance == 0)
                    begin = i;
                balance++;
                len++;
            }
        }
        if (balance > 0)
            res = max(res, (int)s.size() - begin - balance);
        return res;
    }
};
#endif //LEETCODE2023_N32_H
