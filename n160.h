//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N160_H
#define LEETCODE2023_N160_H
#include "global.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> us;
        while (headA) {
            us.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (us.count(headB))
                return headB;
            headB=headB->next;
        }
        return nullptr;
    }
};
#endif //LEETCODE2023_N160_H
