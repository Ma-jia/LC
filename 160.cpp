//
// Created by m'j'x on 2023/11/21.
//
#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode *> set;
        while (headA) {
            set.insert(headA);
            headA = headA->next;
        }
        while (headB) {

            if (set.count(headB) > 0)return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};