//
// Created by 蒋子涵 on 2023/7/29.
//

#ifndef LEETCODE2023_N22_H
#define LEETCODE2023_N22_H
#include "global.h"

class Solution {
public:
    vector<string> res;
    void findRes(string s, int n, int cnt) {
        if (n == s.size()) {
            if (cnt == 0)
                res.push_back(s);
            return;
        }
        if (cnt < s.size() / 2) {
            s[n] = '(';
            findRes(s, n + 1, cnt + 1);
        }
        if (cnt > 0) {
            s[n] = ')';
            findRes(s, n + 1, cnt - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s(n * 2, '.');
        findRes(s, 0, 0);
        return res;
    }
};
#endif //LEETCODE2023_N22_H
