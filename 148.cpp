//
// Created by m'j'x on 2024/7/20.
//
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return mergeSort(head);
    }

    ListNode *getMid(ListNode *head) {
        if (!head)return head;
        ListNode *slow = head, *fast = head->next;          // 快慢指针，慢指针初始为
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;    // 快指针每次移动两个节点
            slow = slow->next;          // 慢指针每次移动一个节点
        }
        return slow;
    }

    ListNode *mergeTwo(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *node = dummy;
        while (list1 != nullptr || list2 != nullptr) {
            int val1 = list1 == nullptr ? 50001 : list1->val;   // 如果链表1已经遍历完，val1取最大值，保证链表2的节点被选择到
            int val2 = list2 == nullptr ? 50001 : list2->val;   // 如果链表2已经遍历完，val2取最大值，保证链表1的节点被选择到
            if (val1 < val2) {
                // 链表1的节点值更小，加入到合并链表，并更新链表1指向的节点
                node->next = list1;
                list1 = list1->next;
            } else {
                // 链表2的节点值更小，加入到合并链表，并更新链表2指向的节点
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;    // 更新合并链表当前的最后一个节点指向
        }
        return dummy->next;

    }

    ListNode *mergeSort(ListNode *head) {
        if (!head || !head->next)return head;
        ListNode *mid = getMid(head);
        ListNode *rightSorted = mergeSort(mid->next);
        if (mid)mid->next = nullptr;//断链
        ListNode *leftSorted = mergeSort(head);
        return mergeTwo(leftSorted, rightSorted);
    }
};