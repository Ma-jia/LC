//
// Created by m'j'x on 2023/11/23.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *current = slow->next;
        ListNode *next = nullptr;
        while (current->next) {
            next = current->next;
            current->next = next->next;
            next->next = slow->next;
            slow->next = next;
        }
        ListNode *f1 = head;
        ListNode *f2 = slow->next;
        while (f1 && f2) {
            if (f1->val != f2->val)return false;
            f1 = f1->next;
            f2 = f2->next;
        }
        return true;
    }
};
