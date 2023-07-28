//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N21_H
#define LEETCODE2023_N21_H
#include "global.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode *dummy = new ListNode, *p = dummy;
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
        else if (list2)
            p->next = list2;
        return dummy->next;
    }
};
#endif //LEETCODE2023_N21_H
