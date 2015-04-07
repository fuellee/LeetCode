/*
 * Recover_Binary_Search_Tree.cpp
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    int n=0;
    TreeNode* mistakes[2];
    TreeNode *pre=nullptr;
    void findMistake(TreeNode *root) {
        if(root==nullptr) return;
        
        findMistake(root->left);
        if(pre!=nullptr && pre->val>root->val) {
            if(n==0) { // first reversed pair
                mistakes[0] = pre;
                mistakes[1] = root;
                n++;
            }
            else { // second reversed pair
                mistakes[1] = root;
            }
        }
        pre = root;
        findMistake(root->right);

    }
public:
    void recoverTree(TreeNode *root) {
        findMistake(root);
        swap(mistakes[0]->val,mistakes[1]->val);
    }
};
int main() {
    
    return 0;
}
