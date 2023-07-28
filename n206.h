//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N206_H
#define LEETCODE2023_N206_H
#include "global.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode *p, *q, *r;
        p = nullptr;
        q = head;
        r = head->next;
        while (q) {
            q->next = p;
            p = q;
            q = r;
            if (r)
                r = r->next;
        }
        return p;
    }
};
#endif //LEETCODE2023_N206_H
