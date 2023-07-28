//
// Created by 58253 on 2023/7/22.
//

#ifndef LEETCODE2023_N416_H
#define LEETCODE2023_N416_H
#include "global.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i:nums)
            sum += i;
        if (sum % 2)
            return false;
        sum /= 2;
        unordered_set<int> collection{0};
        for (int i: nums) {
            if (collection.count(sum - i))
                return true;
            unordered_set<int> next;
            for (int j:collection)
                next.insert(i + j);
            collection.insert(next.begin(), next.end());
        }
        return false;
    }
};
#endif //LEETCODE2023_N416_H
