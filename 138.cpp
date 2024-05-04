#include <unordered_map>

//
// Created by m'j'x on 2023/11/19.
//
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head)return nullptr;
        Node *flag = head;
        std::unordered_map<Node *, Node *> map;
        while (flag) {
            map[flag] = new Node(flag->val);
            flag = flag->next;
        }
        flag = head;
        while (flag) {
            map[flag]->next = map[flag->next];
            map[flag]->random = map[flag->random];
            flag = flag->next;
        }
        return map[head];
    }
};