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
    TreeNode* N[2];
    void findMistake(TreeNode *root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return;
        if(root->left!=NULL) {
            TreeNode* &left = root->left;
            if(root->val < left->val) {
                N[n]=left;
                if(++n==2) return;
            }
            else findMistake(left);
        }
        if(root->right!=NULL) {
            TreeNode* &right = root->right;
            if(root->val > right->val) {
                N[n]=right;
                if(++n==2) return;
            }
            else findMistake(right);
        }
    }
public:
    void recoverTree(TreeNode *root) {
        findMistake(root);
        swap(N[0]->val,N[1]->val);
    }
};
int main() {
    
    return 0;
}
