//
// Created by 58253 on 2023/7/15.
//

#ifndef LEETCODE2023_N138_H
#define LEETCODE2023_N138_H
#include "global.h"

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> map;
        Node *p = head;
        while (p) {
            map[p] = new Node(p->val);
            p = p->next;
        }
        for (auto npair: map) {
            npair.second->next = npair.first->next ? map[npair.first->next] : nullptr;
            npair.second->random = npair.first->random ? map[npair.first->random] : nullptr;
        }
        return map[head];
    }
};
#endif //LEETCODE2023_N138_H
