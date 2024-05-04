//
// Created by m'j'x on 2023/11/23.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next)return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy->next;
        ListNode *flag = nullptr;
        while (current->next) {
            flag = current->next;
            current->next = flag->next;
            flag->next = dummy->next;
            dummy->next = flag;
        }
        ListNode *result = dummy->next;
        delete dummy;

        return result;
    }
};
