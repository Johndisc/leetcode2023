//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N142_H
#define LEETCODE2023_N142_H
#include "global.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> set;
        while (head) {
            if (set.count(head))
                return head;
            set.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
#endif //LEETCODE2023_N142_H
