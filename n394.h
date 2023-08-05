//
// Created by 蒋子涵 on 2023/8/5.
//

#ifndef LEETCODE2023_N394_H
#define LEETCODE2023_N394_H
#include "global.h"

class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                stk.emplace("[");
            } else if (isdigit(s[i])) {
                int j = i + 1;
                while (isdigit(s[j]))
                    j++;
                stk.push(s.substr(i, j - i));
                i = j - 1;
            } else if (isalpha(s[i])) {
                int j = i + 1;
                while (isalpha(s[j]))
                    j++;
                string sub = s.substr(i, j - i);
                if (!stk.empty() && stk.top() != "[") {
                    sub = stk.top() + sub;
                    stk.pop();
                }
                stk.push(sub);
                i = j - 1;
            } else {
                string sub = stk.top();
                stk.pop();
                stk.pop();
                int num = stoi(stk.top());
                stk.pop();
                string multi;
                for (int j = 0; j < num; ++j)
                    multi += sub;
                if (!stk.empty() && stk.top() != "[") {
                    multi = stk.top() + multi;
                    stk.pop();
                }
                stk.push(multi);
            }
        }
        return stk.top();
    }
};
#endif //LEETCODE2023_N394_H
