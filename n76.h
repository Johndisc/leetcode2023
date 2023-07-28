//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N76_H
#define LEETCODE2023_N76_H
#include "global.h"

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tnum, curnum;
        queue<int> pos;
        for (char c:t)
            tnum[c]++;
        int ep = 0;
        int diff = tnum.size();
        while (ep < s.size() && diff != 0) {
            if (tnum[s[ep]]) {
                curnum[s[ep]]++;
                pos.push(ep);
                if (curnum[s[ep]] == tnum[s[ep]])
                    diff--;
            }
            ep++;
        }
        if (ep == s.size() && diff != 0)
            return "";
        while (curnum[s[pos.front()]] > tnum[s[pos.front()]]) {
            curnum[s[pos.front()]]--;
            pos.pop();
        }
        int ms = pos.front(), me = ep;
        while (ep < s.size()) {
            if (tnum[s[ep]]) {
                curnum[s[ep]]++;
                pos.push(ep);
                while (curnum[s[pos.front()]] > tnum[s[pos.front()]]) {
                    curnum[s[pos.front()]]--;
                    pos.pop();
                }
            }
            ep++;
            if (ep - pos.front() < me - ms) {
                ms = pos.front();
                me = ep;
            }
        }
        while (curnum[s[pos.front()]] > tnum[s[pos.front()]]) {
            curnum[s[pos.front()]]--;
            pos.pop();
        }
        if (ep - pos.front() < me - ms) {
            ms = pos.front();
            me = ep;
        }
        return s.substr(ms, me - ms);
    }
};
#endif //LEETCODE2023_N76_H
