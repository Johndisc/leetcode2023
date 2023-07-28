//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N2_H
#define LEETCODE2023_N2_H
#include "global.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode, *p = dummy;
        int carry = 0;
        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(sum % 10);
            p = p->next;
            carry = sum >= 10;
        }
        if (carry)
            p->next = new ListNode(1);
        return dummy->next;
    }
};
#endif //LEETCODE2023_N2_H
