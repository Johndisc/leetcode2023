//
// Created by 58253 on 2023/7/12.
//

#ifndef LEETCODE2023_N42_H
#define LEETCODE2023_N42_H
#include "global.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int midpos = 0;
        int total = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] > total) {
                midpos = i;
                total = height[i];
            }
        }
        total = 0;
        int base = 0;
        for (int i = 0; i < midpos; ++i) {
            if (height[i] < height[base])
                total += height[base] - height[i];
            else
                base = i;
        }
        base = height.size() - 1;
        for (int i = height.size() - 1; i > midpos; --i) {
            if (height[i] < height[base])
                total += height[base] - height[i];
            else
                base = i;
        }
        return total;
    }
};
#endif //LEETCODE2023_N42_H
