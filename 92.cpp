//
// Created by m'j'x on 2023/11/16.
//
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;


        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        ListNode *current = prev->next;
        ListNode *next = nullptr;


        for (int i = 0; i < right - left; ++i) {
            next = current->next;
            current->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        ListNode *result = dummy->next;
        delete dummy;

        return result;
    }
};