//
// Created by 蒋子涵 on 2023/9/11.
//

#ifndef LEETCODE2023_N82_H
#define LEETCODE2023_N82_H
#include "global.h"

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
			return head;
		ListNode *dummy = new ListNode;
		dummy->next = head;
		ListNode *p, *q, *r;
		p = dummy;
		r = head;
		q = head->next;
		bool del = false;
		while (q) {
			if (q->val == r->val)
				del = true;
			else if (del) {
				p->next = q;
				del = false;
			}
			else {
				p = r;
			}
			q = q->next;
			r = r->next;
		}
		if (del) {
			p->next = nullptr;
		}
		return dummy->next;
	}
};
#endif //LEETCODE2023_N82_H
