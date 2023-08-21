//
// Created by 蒋子涵 on 2023/8/7.
//

#ifndef LEETCODE2023_N328_H
#define LEETCODE2023_N328_H
#include "global.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *p, *q, *r, *odd, *even;
        ListNode *dummy = new ListNode;
        r = dummy;
        if (!head)
            return head;
        p = head;
        q = head->next;
        odd = p;
        even = q;
        int i = 0;
        while (q) {
            p->next = q->next;
            r = p;
            p = q;
            q = q->next;
            i++;
        }
        if (i % 2)
            r->next = even;
        else
            p->next = even;
        return odd;
    }
};
#endif //LEETCODE2023_N328_H
