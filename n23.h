//
// Created by 58253 on 2023/7/16.
//

#ifndef LEETCODE2023_N23_H
#define LEETCODE2023_N23_H
#include "global.h"

class Solution {
public:
    class cmp {
    public:
        bool operator() (const ListNode *p1, const ListNode *p2) {
            return p1->val > p2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for(auto ln:lists)
            if (ln)
                pq.push(ln);
        if (pq.empty())
            return nullptr;
        ListNode *dummy = new ListNode, *p = dummy;
        while (!pq.empty()) {
            p->next = pq.top();
            p = p->next;
            pq.pop();
            if (p->next)
                pq.push(p->next);
        }
        return dummy->next;
    }
};
#endif //LEETCODE2023_N23_H
