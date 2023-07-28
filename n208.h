//
// Created by 58253 on 2023/7/16.
//

#ifndef LEETCODE2023_N208_H
#define LEETCODE2023_N208_H
#include "global.h"

class Trie {
public:
    struct TrieNode {
        vector<TrieNode *> leaves;
        bool isend;
        TrieNode() {
            leaves.resize(26, nullptr);
            isend = false;
        }
    };

    TrieNode *root;
    Trie() {
        root = new TrieNode;
    }

    void insert(string word) {
        TrieNode *p = root;
        for (char c: word) {
            if (p->leaves[c - 'a'])
                p = p->leaves[c - 'a'];
            else {
                p->leaves[c - 'a'] = new TrieNode;
                p = p->leaves[c - 'a'];
            }
        }
        p->isend = true;
    }

    bool search(string word) {
        TrieNode *p = root;
        for (char c: word) {
            if (!p->leaves[c - 'a'])
                return false;
            p = p->leaves[c - 'a'];
        }
        return p->isend;
    }

    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (char c: prefix) {
            if (!p->leaves[c - 'a'])
                return false;
            p = p->leaves[c - 'a'];
        }
        return true;
    }
};
#endif //LEETCODE2023_N208_H
