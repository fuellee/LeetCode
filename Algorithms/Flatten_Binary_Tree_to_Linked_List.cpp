/*
 * Flatten_Binary_Tree_to_Linked_List.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x,TreeNode *left=nullptr,TreeNode *right=nullptr) : val(x), left(left), right(right) {}
    void show() {
        if(this->left) this->left->show();
        cout<<this->val<<" ";
        if(this->right) this->right->show();
    }
};

class Solution {
    TreeNode *pre=nullptr;
public:
    void flatten(TreeNode *root) {
        if(root==nullptr) return;
        auto left=root->left,right=root->right;
        if(pre) {
            pre->right = root;
            pre->left = nullptr;
        }
        pre = root;
        flatten(left);
        flatten(right);
    }
};
int main() {
    #define N new TreeNode
    Solution s; 
    // auto tree = N(1,nullptr,N(2));
    auto tree = N(1,
                  N(2,
                    N(3),
                    N(4)),
                  N(5));
    s.flatten(tree);
    tree->show();
    return 0;
}
