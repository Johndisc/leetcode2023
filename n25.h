//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N25_H
#define LEETCODE2023_N25_H
#include "global.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1)
            return head;
        ListNode *dummy = new ListNode;
        dummy->next = head;
        ListNode *p = dummy, *q = p->next, *r = q->next;
        ListNode *pre = p, *first = head;
        ListNode *mid;
        while (true) {
            for (int i = 0; i < k - 1; ++i) {
                p = q;
                q = r;
                r = r->next;
                q->next = p;
            }
            pre->next = q;
            first->next = r;
            pre = first;
            first = r;
            int num = 0;
            ListNode *tmp = r;
            while (tmp) {
                num++;
                tmp = tmp->next;
            }
            if (num < k)
                break;
            q = r;
            r = r->next;
        }
        return dummy->next;
    }
};
#endif //LEETCODE2023_N25_H
