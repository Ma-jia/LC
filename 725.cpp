//
// Created by m'j'x on 2023/11/24.
//
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        vector<ListNode *> myVector(k, nullptr);
        int length = 0;
        ListNode *temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            length++;
        }
        int size = length / k;
        int many = length % k;
        ListNode *curr = head;
        for (int i = 0; i < k && curr != nullptr; i++) {
            myVector[i] = curr;
            int flag = size + (i < many ? 1 : 0);
            for (int j = 0; j < flag - 1; j++) {
                if (curr != nullptr) {
                    curr = curr->next;
                }
            }
            if (curr != nullptr) {
                ListNode *nextNode = curr->next;
                curr->next = nullptr;
                curr = nextNode;
            }
        }
        return myVector;
    }
};