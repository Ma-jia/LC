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
    ListNode *oddEvenList(ListNode *head) {
        if (!head)return head;
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *flag = second;
        while (second && second->next) {

            first->next = second->next;
            first = first->next;
            second->next = second->next->next;
            second = second->next;
        }
        first->next = flag;
        delete first;
        delete second;
        delete flag;
        return head;
    }
};
