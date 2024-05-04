#include <iostream>

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        int len = 1;
        ListNode *curr = head;
        while (curr->next) {
            curr = curr->next;
            len++;
        }

        if (k % len == 0) {
            return head;
        }

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *flag = dummy;
        for (int i = 0; i < k % len; i++) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = flag->next;
        flag->next = slow->next;
        slow->next = nullptr;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};

void printList(ListNode *head) {
    ListNode *curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

ListNode *createList(int arr[], int n) {
    if (n == 0) {
        return nullptr;
    }
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void deleteList(ListNode *head) {
    ListNode *curr = head;
    while (curr != nullptr) {
        ListNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    // Test Case 1
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode *head1 = createList(arr1, n1);
    int k1 = 2;
    ListNode *rotated1 = solution.rotateRight(head1, k1);
    std::cout << "Rotated List 1: ";
    printList(rotated1);
    deleteList(rotated1);

    // Test Case 2
    int arr2[] = {0, 1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode *head2 = createList(arr2, n2);
    int k2 = 4;
    ListNode *rotated2 = solution.rotateRight(head2, k2);
    std::cout << "Rotated List 2: ";
    printList(rotated2);
    deleteList(rotated2);

    // Test Case 3
    int arr3[] = {1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    ListNode *head3 = createList(arr3, n3);
    int k3 = 0;
    ListNode *rotated3 = solution.rotateRight(head3, k3);
    std::cout << "Rotated List 3: ";
    printList(rotated3);
    deleteList(rotated3);

    return 0;
}