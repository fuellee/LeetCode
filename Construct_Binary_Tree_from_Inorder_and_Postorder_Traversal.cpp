/*
 * Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    typedef vector<int>::iterator it;
    TreeNode *buildTree(it inB, it  postB, int size) {
        if(size<1)
            return nullptr;
        else {
            int val = *(postB+size-1);
            it inPos = find(inB,inB+size-1,val);
            int ltreeSize = inPos-inB;
            TreeNode *subtree = new TreeNode(val);
            subtree->left = buildTree(inB, postB, ltreeSize);
            subtree->right = buildTree(inPos+1, postB+ltreeSize, size-ltreeSize-1);
            return subtree;
        }
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder.begin(), postorder.begin(), inorder.size());
    }
};
int main() {
    // vector<int> inorder{-1},postorder{-1};
    // vector<int> inorder{2,1},postorder{2,1};
    vector<int> inorder{1,2},postorder{2,1};
    Solution s;
    s.buildTree(inorder,postorder);
    return 0;
}
