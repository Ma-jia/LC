//
// Created by m'j'x on 2023/11/21.
//
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *flag = dummy;
        while (flag && flag->next) {
            if (flag->next->val == val) {
                flag->next = flag->next->next;
            } else flag = flag->next;
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};