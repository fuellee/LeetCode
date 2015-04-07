/*
 * Binary_Tree_Level_Order_Traversal.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;
// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode* left=nullptr, TreeNode* right=nullptr) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) { 
        if(root==nullptr) return {};
        vector<vector<int> > res;
        vector<TreeNode*> *curlevel = new vector<TreeNode*>{root};
        while(curlevel->size()) {
            res.push_back({});
            vector<int> &curvals = res[res.size()-1];
            vector<TreeNode*> *nextlevel = new vector<TreeNode*>{};
            for(auto p : *curlevel) {
                curvals.push_back(p->val);
                if(p->left!=nullptr) nextlevel->push_back(p->left);
                if(p->right!=nullptr) nextlevel->push_back(p->right);
            }
            delete curlevel;
            curlevel=nextlevel;
        }
        return res;
    }
};
int main() {
    #define N new TreeNode
    TreeNode *tree =  N(3,N(9),N(20));
    Solution s;
    cout<<"[\n";
    for (auto level : s.levelOrder(tree)) {
        cout<<"  [";
        for(auto e : level) 
            cout<<e<<" ";
        cout<<"]\n";
    }
    cout<<"]\n";
    return 0;
}
