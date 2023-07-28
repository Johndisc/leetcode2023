//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N19_H
#define LEETCODE2023_N19_H
#include "global.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode, *slow = dummy, *fast = dummy;
        dummy->next = head;
        for (int i = 0; i < n - 1; ++i)
            fast = fast->next;
        while (fast->next->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
#endif //LEETCODE2023_N19_H
