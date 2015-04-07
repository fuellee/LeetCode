/*
 * Convert_Sorted_Array_to_Binary_Search_Tree.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *sortedArrayToBST(vector<int>::iterator B, int size) {
        if(size<=0) return nullptr;
        int mid = size/2;
        TreeNode *root = new TreeNode(B[mid]);
        root->left = sortedArrayToBST(B,mid);
        root->right = sortedArrayToBST(B+mid+1,size-mid-1);
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num.begin(),num.size());
    }
};
int main() {
    return 0;
}
