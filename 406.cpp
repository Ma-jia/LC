//
// Created by m'j'x on 2023/11/23.
//
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *k1 = reverseList(l1);
        ListNode *k2 = reverseList(l2);
        return reverseList(addTwoNumberss(k1, k2));
    }

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

    ListNode *addTwoNumberss(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr;
        ListNode *p = head;
        int flag = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l1 ? l2->val : 0;
            int sum = n1 + n2 + flag;

            if (!p) {
                head = p = new ListNode(sum % 10);
            } else {
                p->next = new ListNode(sum % 10);
                p = p->next;
            }
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
            flag = sum / 10;
        }
        if (flag > 0) {
            p->next = new ListNode(flag);
        }
        return head;
    }
};