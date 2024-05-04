//
// Created by m'j'x on 2023/11/20.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) {
            return; // 如果链表为空或只有一个节点，无需重新排序
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *current = slow->next;
        ListNode *next = nullptr;
        while (current->next) {
            next = current->next;
            current->next = next->next;
            next->next = slow->next;
            slow->next = next;
        }
        fast = head;
        ListNode *flag = nullptr;
        while (fast != slow) {
            flag = fast->next;
            next = slow->next->next;

            fast->next = slow->next;
            fast = flag;

            slow->next->next = fast;
            slow->next = next;

        }
//        ListNode* p1 = head;
//        ListNode* p2 = slow->next;
//        while (p1 != slow) {
//
//            slow->next = p2->next;
//            p2->next = p1->next;
//            p1->next = p2;
//            p1 = p2->next;
//            p2 = slow->next;
//        }


    }
};

void printList(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // 测试用例1：空链表
    ListNode *head1 = nullptr;
    solution.reorderList(head1);
    printList(head1);  // 预期输出: ""

    // 测试用例2：只有一个节点的链表
    ListNode *head2 = new ListNode(1);
    solution.reorderList(head2);
    printList(head2);  // 预期输出: "1"

    // 测试用例3：只有两个节点的链表
    ListNode *head3 = new ListNode(1);
    head3->next = new ListNode(2);
    solution.reorderList(head3);
    printList(head3);  // 预期输出: "1 2"

    // 测试用例4：含有多个节点的链表
    ListNode *head4 = new ListNode(1);
    head4->next = new ListNode(2);
    head4->next->next = new ListNode(3);
    head4->next->next->next = new ListNode(4);
    head4->next->next->next->next = new ListNode(5);
    solution.reorderList(head4);
    printList(head4);  // 预期输出: "1 5 2 4 3"

    return 0;
}
