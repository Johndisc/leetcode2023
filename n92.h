//
// Created by 蒋子涵 on 2023/9/21.
//

#ifndef LEETCODE2023_N92_H
#define LEETCODE2023_N92_H
#include "global.h"

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int left, int right) {
		ListNode *dummy, *p, *q, *r, *pre, *last;
		dummy = new ListNode;
		dummy->next = head;
		pre = dummy;
		int pos = 1;
		while (pos != left) {
			pos++;
			pre = pre->next;
		}
		last = pre->next->next;
		while (pos != right) {
			pos++;
			last = last->next;
		}
		p = pre;
		q = p->next;
		r = q->next;
		while (q != last) {
			q->next = p;
			p = q;
			q = r;
			if (r)
				r = r->next;
		}
		pre->next->next = last;
		pre->next = p;
		return dummy->next;
	}
};
#endif //LEETCODE2023_N92_H
