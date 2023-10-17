//
// Created by 蒋子涵 on 2023/9/11.
//

#ifndef LEETCODE2023_N86_H
#define LEETCODE2023_N86_H
#include "global.h"

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode *left, *right, *small, *big, *p = head;
		left = new ListNode;
		right = new ListNode;
		small = left;
		big = right;
		while (p) {
			if (p->val < x) {
				left->next = p;
				left = left->next;
				p = p->next;
			}
			else {
				right->next = p;
				right = right->next;
				p = p->next;
			}
		}
		right->next = nullptr;
		left->next = big->next;
		return small->next;
	}
};
#endif //LEETCODE2023_N86_H
