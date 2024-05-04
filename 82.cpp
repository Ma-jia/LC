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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *flag = dummy->next;

        ListNode *z = dummy;
        int v = flag->val;
        int k = 0;

        while (flag->next) {
            if (flag->next->val == v) {
                k++;
                flag = flag->next;
            } else {
                if (k >= 1) {
                    z->next = flag->next;
                    delete flag;
                    flag = z->next;
                    v = flag->val;
                    k = 0;

                } else {
                    flag = flag->next;
                    v = flag->val;
                    z = z->next;
                }
            }

        }
        if (k != 0) {
            z->next = nullptr;
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};