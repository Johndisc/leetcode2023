//
// Created by 58253 on 2023/7/10.
//

#ifndef LEETCODE2023_N49_H
#define LEETCODE2023_N49_H
#include "global.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<set<char>, vector<string>> um;
        for (auto it: strs) {
            set<char> cs(it.begin(), it.end());
            um[cs].push_back(it);
        }
        vector<vector<string>> res;
        for (auto vs: um) {
            res.push_back(vs.second());
        }
        return res;
    }
};

#endif //LEETCODE2023_N49_H
