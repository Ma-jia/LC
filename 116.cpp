//
// Created by m'j'x on 2024/8/8.
//
#include <vector>
#include <stack>
#include <queue>
#include <cassert>
#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        Node *dummy = root;
        if (root == nullptr)return root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *nodePre;
            Node *node;
            int nb = q.size();
            for (int i = 0; i < nb; ++i) {
                Node *curr = q.front();
                if (i == 0) {
                    q.pop();
                    node = curr;
                } else {
                    q.pop();
                    nodePre = curr;
                    node->next = nodePre;
                    node = node->next;
                }



                // 将左子节点入队
                if (curr->left) {
                    q.push(curr->left);
                }
                // 将右子节点入队
                if (curr->right) {
                    q.push(curr->right);
                }
            }


        }
        return dummy;
    }
};