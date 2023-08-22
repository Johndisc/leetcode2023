//
// Created by 蒋子涵 on 2023/8/23.
//

#ifndef LEETCODE2023_N131_H
#define LEETCODE2023_N131_H
#include "global.h"

class Solution {
public:
    vector<vector<string>> res;

    bool check(string &s, int sp, int ep) {
        while (sp < ep) {
            if (s[sp] != s[ep])
                return false;
            sp++;
            ep--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> cur_res;
        if (s.empty()) {
            cur_res.emplace_back();
        }
        for (int i = 0; i < s.size(); ++i) {
            if (check(s, 0, i)) {
                auto single = partition(s.substr(i + 1, s.size() - i - 1));
                for(auto &it: single) {
                    vector<string> tmp{s.substr(0, i + 1)};
                    tmp.insert(tmp.end(), it.begin(), it.end());
                    cur_res.push_back(tmp);
                }
//                cur_res.insert(cur_res.end(), single.begin(), single.end());
            }
        }
        return cur_res;
    }
};
#endif //LEETCODE2023_N131_H
