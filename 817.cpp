//
// Created by m'j'x on 2023/11/26.
//

#include <vector>
#include <unordered_set>

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
    int numComponents(ListNode *head, vector<int> &nums) {
        std::unordered_set<int> hashSet;
        int ans = 0;
        int flag = 0;
        for (int num: nums) {
            hashSet.insert(num);
        }
        ListNode *p = head;
        while (p) {
            if (hashSet.count(p->val)) {
                if (flag == 0) {
                    ans++;
                    flag = 1;
                }
            } else flag = 0;
            p = p->next;
        }
        return ans;
    }
};