//
// Created by m'j'x on 2023/12/12.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;
//
//class Solution {
//public:
//    vector<int> nextGreaterElements(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> ans(n, -1);  // 初始化大小为n的结果数组，全部赋值为-1
//        stack<int> stk;  // 用于临时存放元素索引
//        for (int i = 0; i < 2 * n; ++i) {
//            while (!stk.empty() && nums[i % n] > nums[stk.top()]) {
//                ans[stk.top()] = nums[i % n];  // 当前元素是栈顶元素的下一个更大元素
//                stk.pop();
//            }
//            if (i < n) {
//                stk.push(i);  // 只在第一轮遍历时将元素索引入栈
//            }
//        }
//        return ans;
//    }
//};

#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = 2 * n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[i % n] >= stk.top()) {
                stk.pop();
            }
            if (i < n)ans[i] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i % n]);
        }

        return ans;
    }
};

//class Solution {
//public:
//    vector<int> nextGreaterElements(vector<int>& nums) {
//        std::vector<int> copiedVector = nums;
//        int n=nums.size();
//        // 将copiedVector连接到originalVector
//        nums.insert(nums.end(), copiedVector.begin(), copiedVector.end());
//
//        vector<int> ans(n, 0);
//        stack<int> stk;
//        for (int i = 2*n-1; i >= 0; --i) {
//            while (!stk.empty() && nums[i]>= stk.top()) {
//                stk.pop();
//            }
//            if(i<n)ans[i] = stk.empty() ? -1 : stk.top();
//            stk.push(nums[i]);
//        }
//
//        return ans;
//    }
//};
int main() {
    Solution sol;

    // 测试用例1：正常情况
    vector<int> nums1 = {100, 1, 11, 1, 120, 111, 123, 1, -1, -100};
    // 预期输出: [2, -1, 2]vector<int> nums1 = {100,1,11,1,120,111,123,1,-1,-100};
    vector<int> result1 = sol.nextGreaterElements(nums1);

    // 测试用例2：空数组
    vector<int> nums2;
    // 预期输出: []
    vector<int> result2 = sol.nextGreaterElements(nums2);

    // 测试用例3：只有一个元素
    vector<int> nums3 = {5};
    // 预期输出: [-1]
    vector<int> result3 = sol.nextGreaterElements(nums3);

    // 输出测试结果
    cout << "Test case 1 result: ";
    for (int num: result1) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Test case 2 result: ";
    for (int num: result2) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Test case 3 result: ";
    for (int num: result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}