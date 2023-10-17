//
// Created by 蒋子涵 on 2023/8/29.
//

#ifndef LEETCODE2023_N347_H
#define LEETCODE2023_N347_H
#include "global.h"

class Solution {
public:
    void adjust(vector<pair<int, int>> &t, int n, int index) {
        int mid = index;
        int left = mid * 2 + 1;
        int right = mid * 2 + 2;
        if (left < n && t[mid].first > t[left].first) {
            mid = left;
        }
        if (right < n && t[mid].first > t[right].first) {
            mid = right;
        }
        if (mid != index) {
            swap(t[mid], t[index]);
            adjust(t, n, mid);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> times;
        for (int i: nums) {
            times[i]++;
        }
        vector<pair<int, int>> t;
        for (auto item: times) {
            t.emplace_back(item.second, item.first);
        }
        for (int i = k - 1; i >= 0; --i) {
            adjust(t, k, i);
        }
        for (int i = k; i < t.size(); ++i) {
            if (t[i].first > t[0].first) {
                swap(t[i], t[0]);
                adjust(t, k, 0);
            }
        }
        vector<int> res(k);
        for (int i = 0; i < k; ++i) {
            res[i] = t[i].second;
        }
        return res;
    }
};
#endif //LEETCODE2023_N347_H
