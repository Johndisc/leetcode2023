//
// Created by 蒋子涵 on 2023/8/19.
//

#ifndef LEETCODE2023_N310_H
#define LEETCODE2023_N310_H
#include "global.h"

class Solution {
public:
    int dfs(int i, int pre, vector<vector<int>> &inedge, int depth){
        int max_depth = depth;
        for (int dest: inedge[i]) {
            if (dest != pre)
                max_depth = max(max_depth, dfs(dest, i, inedge, depth + 1));
        }
        return max_depth;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<vector<int>> inedge(n, vector<int>());
        for (auto &vec: edges) {
            inedge[vec[0]].push_back(vec[1]);
            inedge[vec[1]].push_back(vec[0]);
        }
        int min_depth = INT_MAX;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int d = dfs(i, -1, inedge, 0);
            if (d < min_depth) {
                res.clear();
                res.push_back(i);
                min_depth = d;
            }
            else if (d == min_depth) {
                res.push_back(i);
            }
        }
        return res;
    }
};
#endif //LEETCODE2023_N310_H
