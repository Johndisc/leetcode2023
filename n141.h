//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N141_H
#define LEETCODE2023_N141_H
#include "global.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};
#endif //LEETCODE2023_N141_H
