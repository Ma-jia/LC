//
// Created by m'j'x on 2023/11/9.
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
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr;
        ListNode *p = head;
        int flag = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
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

// 程序入口
int main() {
    // 创建两个数字链表
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // 创建解决方案对象
    Solution solution;

    // 调用函数计算结果
    ListNode *result = solution.addTwoNumbers(l1, l2);

    // 输出结果
    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
