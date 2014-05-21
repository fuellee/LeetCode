/*
 * Binary_Tree_Maximum_Path_Sum.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode *left=nullptr, TreeNode *right=nullptr) : val(x), left(left), right(right) {}
};

class Solution {
    int maxSum = INT_MIN;
    int maxPathSum_(TreeNode *root) {
        if(root==nullptr) return 0;
        else {
            int lsum=max(0,maxPathSum_(root->left)) ,rsum=max(0,maxPathSum_(root->right));
            int sum = lsum + root->val + rsum;
            maxSum = sum>maxSum? sum: maxSum;
            return root->val +max(lsum,rsum); 
        }
    }
public:
    int maxPathSum(TreeNode *root) {
        maxSum=INT_MIN;
        maxPathSum_(root);
        return maxSum;
    }
};
int main() {
    Solution s;
    #define T new TreeNode 
    // auto tree=T(2,T(-1),nullptr);
    auto tree=T(1,T(2),T(3));
    int res =s.maxPathSum(tree);
    cout<<res;
    return 0;
}
