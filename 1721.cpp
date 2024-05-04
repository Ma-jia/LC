//
// Created by m'j'x on 2023/11/28.
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
    ListNode *swapNodes(ListNode *head, int k) {
        if (!head || !head->next)return head;
        ListNode *curr = head;
        ListNode *first = nullptr;
        ListNode *second = head;
        for (int i = 1; i < k; ++i) {

            if (!curr) return head;
            curr = curr->next;
        }
        first = curr;
        while (curr->next) {
            curr = curr->next;
            second = second->next;
        }

        swap(first->val, second->val);
        return head;

    }

};
