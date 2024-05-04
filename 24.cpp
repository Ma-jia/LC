//
// Created by m'j'x on 2023/11/15.
//
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *flag = dummy;

        while (flag->next && flag->next->next) {
            ListNode *f1 = flag->next;
            ListNode *f2 = flag->next->next;

            f1->next = f2->next;
            f2->next = f1;
            flag->next = f2;
            flag = flag->next->next;
        }
        return dummy->next;
    }
};