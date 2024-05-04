//
// Created by m'j'x on 2023/11/13.
//
#include <iostream>
#include <cstdlib>


struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *fast = dummy;
        ListNode *slow = dummy;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }

};

void printList(ListNode *head) {
    ListNode *current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // 创建链表：1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;

    Solution solution;

//    // 测试用例1：删除倒数第2个节点
//    int n1 = 2;
//    ListNode* result1 = solution.removeNthFromEnd(head, n1);
//    printList(result1);  // 输出：1 2 3 5
//
//    // 测试用例2：删除倒数第1个节点
//    int n2 = 1;
//    ListNode* result2 = solution.removeNthFromEnd(head, n2);
//    printList(result2);  // 输出：1 2 3

    // 测试用例3：删除倒数第3个节点（即删除头节点）
    int n3 = 3;
    ListNode *result3 = solution.removeNthFromEnd(head, n3);
    printList(result3);  // 输出：2 3

    // 释放链表所占用的内存
    ListNode *current = result3;
    while (current != nullptr) {
        ListNode *toDelete = current;
        current = current->next;
        delete toDelete;
    }

    return 0;
}