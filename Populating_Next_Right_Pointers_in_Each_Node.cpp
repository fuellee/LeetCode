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
struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x, TreeLinkNode* left=nullptr, TreeLinkNode* right=nullptr) : val(x), left(left), right(right) {}
    void pl() {
        if(this->next==nullptr) cout<<this->val<<endl;
        else {
            cout<<this->val<<"->";
            this->next->pl();
        }
    }
};

class Solution {
public:
    void connect(TreeLinkNode* p) {
        if (p == NULL || p->left == NULL || p->right == NULL)
            return;
        TreeLinkNode* rightSibling;
        TreeLinkNode* p1 = p;
        while (p1) {
            if (p1->next)
                rightSibling = p1->next->left;
            else
                rightSibling = NULL;
            p1->left->next = p1->right;
            p1->right->next = rightSibling;
            p1 = p1->next;

        }
        connect(p->left);
    }
    vector<vector<int> > levelOrder(TreeLinkNode *root) { 
        if(root==nullptr) return {};
        vector<vector<int> > res;
        vector<TreeLinkNode*> *curlevel = new vector<TreeLinkNode*>{root};
        while(curlevel->size()) {
            (*curlevel)[0]->pl();
            res.push_back({});
            vector<int> &curvals = res[res.size()-1];
            vector<TreeLinkNode*> *nextlevel = new vector<TreeLinkNode*>{};
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
    #define N new TreeLinkNode
    TreeLinkNode *tree =  N(0,
                            N(1,N(3),N(4)),
                            N(2,N(5),N(6)));
    Solution s;
    s.connect(tree);
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
