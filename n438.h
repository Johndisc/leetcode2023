//
// Created by 58253 on 2023/7/13.
//

#ifndef LEETCODE2023_N438_H
#define LEETCODE2023_N438_H
#include "global.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> map;
        vector<int> res;
        if (p.size() > s.size())
            return res;
        for (char c: p)
            map[c]++;
        for (int i = 0; i < p.size(); ++i) {
            if (map[s[i]] == 1)
                map.erase(s[i]);
            else
                map[s[i]]--;
        }
        for (int i = 0; i < s.size() - p.size(); ++i) {
            if (map.empty())
                res.push_back(i);
            if (map[s[i]] == -1)
                map.erase(s[i]);
            else
                map[s[i]]++;
            if (map[s[i + p.size()]] == 1)
                map.erase(s[i + p.size()]);
            else
                map[s[i + p.size()]]--;
        }
        if (map.empty())
            res.push_back(s.size() - p.size());
        return res;
    }
};
#endif //LEETCODE2023_N438_H
