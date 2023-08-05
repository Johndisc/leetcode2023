//
// Created by 蒋子涵 on 2023/7/31.
//

#ifndef LEETCODE2023_N143_H
#define LEETCODE2023_N143_H
#include "global.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next)
            return;
        ListNode *fast, *slow, *p, *q, *m, *n, *even_head = new ListNode;
        fast = slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        even_head->next = nullptr;
        p = slow->next;
        q = p->next;
        slow->next = nullptr;

        while (p) {
            p->next = even_head->next;
            even_head->next = p;
            p = q;
            q = q ? q->next : q;
        }
        p = head;
        m = p->next;
        q = even_head->next;
        n = q->next;
        while (p) {
            p->next = q;
            p = q;
            q = m;
            m = p ? p->next : p;
        }
    }
};
#endif //LEETCODE2023_N143_H
