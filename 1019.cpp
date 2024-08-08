//
// Created by m'j'x on 2024/7/21.
//

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
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

    vector<int> nextLargerNodes(ListNode *head) {
        head = reverseList(head);
        vector<int> ans;
        stack<int> stk; // 单调栈（节点值）
        for (auto cur = head; cur; cur = cur->next) {
            while (!stk.empty() && stk.top() <= cur->val) {
                stk.pop();
            }
            ans.push_back(stk.empty() ? 0 : stk.top());
            stk.push(cur->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};