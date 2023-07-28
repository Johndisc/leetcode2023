//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N234_H
#define LEETCODE2023_N234_H
#include "global.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stack;
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast && fast->next && slow) {
            slow = slow->next;
            fast = fast->next->next;
        }
        while (head != slow) {
            stack.push(head->val);
            head = head->next;
        }
        if (fast)
            slow = slow->next;
        while (slow && !stack.empty()) {
            if (slow->val == stack.top()) {
                slow = slow->next;
                stack.pop();
            } else
                return false;
        }
        return true;
    }
};
#endif //LEETCODE2023_N234_H
