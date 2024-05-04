//
// Created by m'j'x on 2023/11/21.
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
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next)return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = head;
        ListNode *find = nullptr;
        ListNode *flag = nullptr;
        while (current && current->next) {
            if (current->next->val < current->val) {
                find = dummy;
                while (find->next && find->next->val < current->next->val) {
                    find = find->next;
                }
                flag = current->next;
                current->next = flag->next;
                flag->next = find->next;

                find->next = flag;
            } else {
                current = current->next;
            }
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;

    }
};

void printList(ListNode *head) {
    ListNode *curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *createList(int arr[], int n) {
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    for (int i = 0; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return dummy->next;
}

int main() {
    Solution obj;
    ListNode *head;

    // 测试用例1：空链表
    head = NULL;
    ListNode *sortedList1 = obj.insertionSortList(head);
    cout << "Sorted List 1: ";
    printList(sortedList1);

    // 测试用例2：单个节点
    int arr2[] = {10};
    head = createList(arr2, 1);
    ListNode *sortedList2 = obj.insertionSortList(head);
    cout << "Sorted List 2: ";
    printList(sortedList2);

    // 测试用例3：已排序的链表
    int arr3[] = {1, 2, 3, 4, 5};
    head = createList(arr3, 5);
    ListNode *sortedList3 = obj.insertionSortList(head);
    cout << "Sorted List 3: ";
    printList(sortedList3);

    // 测试用例4：逆序链表
    int arr4[] = {5, 4, 3, 2, 1};
    head = createList(arr4, 5);
    ListNode *sortedList4 = obj.insertionSortList(head);
    cout << "Sorted List 4: ";
    printList(sortedList4);

    // 测试用例5：乱序链表
    int arr5[] = {6, 2, -1, 5, 3};
    head = createList(arr5, 5);
    ListNode *sortedList5 = obj.insertionSortList(head);
    cout << "Sorted List 5: ";
    printList(sortedList5);

    return 0;
}