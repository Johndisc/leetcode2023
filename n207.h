//
// Created by 蒋子涵 on 2023/8/6.
//

#ifndef LEETCODE2023_N207_H
#define LEETCODE2023_N207_H
#include "global.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> pre_courses(numCourses), after_courses(numCourses);
        for (auto item: prerequisites) {
            pre_courses[item[0]].insert(item[1]);
            after_courses[item[1]].insert(item[0]);
        }
        bool finished = false;

        while (!finished) {
            finished = true;
            for (int i = 0; i < numCourses; ++i) {
                if (pre_courses[i].empty() && !after_courses[i].empty()) {
                    for (int j: after_courses[i]) {
                        pre_courses[j].erase(i);
                    }
                    after_courses[i].clear();
                    finished = false;
                }
            }
        }
        for (auto st: pre_courses) {
            if (!st.empty())
                return false;
        }
        return true;
    }
};
#endif //LEETCODE2023_N207_H
