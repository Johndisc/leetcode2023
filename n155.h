//
// Created by 蒋子涵 on 2023/7/31.
//

#ifndef LEETCODE2023_N155_H
#define LEETCODE2023_N155_H
#include "global.h"

class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;
    int cur_min = INT_MAX;
    MinStack() {
        minstk.push(cur_min);
    }

    void push(int val) {
        stk.push(val);
        cur_min = min(minstk.top(), val);
        minstk.push(cur_min);
    }

    void pop() {
        if (!stk.empty()) {
            stk.pop();
            minstk.pop();
        }
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};
#endif //LEETCODE2023_N155_H
