//
// Created by 58253 on 2023/7/11.
//

#ifndef LEETCODE2023_N11_H
#define LEETCODE2023_N11_H
#include "global.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size() - 1;
        int area = (e - s) * min(height[s], height[e]);

        while (s < e) {
            area = max((e - s) * min(height[s], height[e]), area);
            if (height[s] < height[e])
                s++;
            else
                e--;
        }
        return area;
    }
};
#endif //LEETCODE2023_N11_H
