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
    ListNode *partition(ListNode *head, int x) {

        ListNode *small = new ListNode(0);

        ListNode *flag1 = small;

        ListNode *large = new ListNode(0);

        ListNode *flag2 = large;


        while (head) {
            if (head->val < x) {
                flag1->next = head;
                flag1 = flag1->next;
            } else {
                flag2->next = head;
                flag2 = flag2->next;
            }
            head = head->next;
        }
        if (head->val < x) {
            flag1->next = head;
        } else {
            flag2->next = head;
        }
        flag1->next = large->next;


        flag2->next = nullptr;
        ListNode *ans = small->next;
        delete small;
        delete large;
        return ans;
    }
};