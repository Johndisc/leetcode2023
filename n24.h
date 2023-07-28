//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N24_H
#define LEETCODE2023_N24_H
#include "global.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode *dummy = new ListNode;
        dummy->next = head;
        ListNode *p = dummy, *q = head, *r = head->next;
        while (q && r) {
            p->next = r;
            q->next = r->next;
            r->next = q;
            p = q;
            q = p->next;
            r = q ? q->next : nullptr;
        }
        return dummy->next;
    }
};
#endif //LEETCODE2023_N24_H
