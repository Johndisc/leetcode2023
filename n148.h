//
// Created by 58253 on 2023/7/16.
//

#ifndef LEETCODE2023_N148_H
#define LEETCODE2023_N148_H
#include "global.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode;
        dummy->next = head;
        ListNode *fast, *slow, *p;
        p = dummy;
        fast = slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            p = p->next;
            slow = slow->next;
        }
        p->next = nullptr;
        ListNode *list1 = sortList(head);
        ListNode *list2 = sortList(slow);

        if (!list1)
            return list2;
        if (!list2)
            return list1;
        p = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                p->next = list1;
                p = list1;
                list1 = list1->next;
            }
            else {
                p->next = list2;
                p = list2;
                list2 = list2->next;
            }
        }
        if (list1)
            p->next = list1;
        else
            p->next = list2;
        return dummy->next;
    }
};
#endif //LEETCODE2023_N148_H
