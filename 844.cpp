//
// Created by m'j'x on 2024/2/5.
//
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = 0;
        int n2 = 0;
        while (!s.empty() && !t.empty()) {

            while (!s.empty()) {

                if (s.back() == '#') {
                    s.pop_back();
                    n++;
//                    cout<<n<<endl;
                } else if (n != 0 && s.back() != '#') {
                    s.pop_back();
                    n--;
                }
                if (n == 0) {
                    break;
                }
            }

            while (!t.empty()) {

                if (t.back() == '#') {
                    t.pop_back();
                    n2++;
                } else if (n2 != 0 && t.back() != '#') {
                    t.pop_back();
                    n2--;
                }
                if (n2 == 0 && t.back() != '#') {
                    break;
                }
            }
            if (s.empty() && t.empty())return true;
            if (s.back() == t.back()) {
                s.pop_back();
                t.pop_back();
            } else return false;

        }
        return true;
    }
};

int main() {
    Solution solution;
    std::string s1 = "a#c";
    std::string t1 = "b";
    std::cout << "Test Case 1: " << (solution.backspaceCompare(s1, t1) ? "true" : "false") << std::endl;

//    std::string s2 = "abc";
//    std::string t2 = "def";
//    std::cout << "Test Case 2: " << (solution.backspaceCompare(s2, t2) ? "true" : "false") << std::endl;
//
//    std::string s3 = "hello";
//    std::string t3 = "hello";
//    std::cout << "Test Case 3: " << (solution.backspaceCompare(s3, t3) ? "true" : "false") << std::endl;

    // 在这里可以添加更多的测试用例...

    return 0;
}