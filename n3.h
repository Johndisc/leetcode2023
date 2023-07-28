//
// Created by 58253 on 2023/7/13.
//

#ifndef LEETCODE2023_N3_H
#define LEETCODE2023_N3_H
#include "global.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
        int left = 0, right = 1;
        int res = 0;
        unordered_set<char> shown{s[0]};
        while (right < s.size()) {
            if (!shown.count(s[right])) {
                shown.insert(s[right]);
                right++;
            } else {
                res = max(res, right - left);
                while (s[left] != s[right]) {
                    shown.erase(s[left]);
                    left++;
                }
                left++;
                right++;
            }
        }
        res = max(res, right - left);
        return res;
    }
};
#endif //LEETCODE2023_N3_H
