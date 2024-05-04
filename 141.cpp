//
// Created by m'j'x on 2023/11/19.
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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)return false;
        std::unordered_set<ListNode *> set;
        ListNode *flag = head;
        while (flag) {
            auto search = set.find(flag);
            if (search != set.end()) {
                return true;
            } else {
                set.insert(flag);
            }
            flag = flag->next;
        }
        return false;
    }
};