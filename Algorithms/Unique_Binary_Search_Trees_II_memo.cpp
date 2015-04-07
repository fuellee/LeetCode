/*
 * Unique_Binary_Search_Trees_II.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    void show() {
        if(this->left) this->left->show();
        cout<<this->val<<" ";
        if(this->right) this->right->show();
    }
};

class Solution {
    map<pair<int,int>, vector<TreeNode *>* > cache;
    vector<TreeNode *>* gen(int start,int end) {
        if(cache.find({start,end})!=cache.end()) return cache[{start,end}];

        if(start>end) {
            auto result = new vector<TreeNode*>{nullptr};
            cache[{start,end}] = result;
            return result;
        }
        else {
            auto res = new vector<TreeNode *>;
            for(int i=start; i<=end; ++i){
                for(auto left : *gen(start,i-1))
                    for(auto right : *gen(i+1,end)){
                        auto root = new TreeNode(i);
                        root->left = left;
                        root->right = right;
                        
                        res->push_back(root);
                    }
            }

            cache[{start,end}] = res;
            return res;
        }
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        return *gen(1,n);
    }
};
int main() {
    Solution s;
    // cout<<s.generateTrees(1).size()<<endl;
    // cout<<s.generateTrees(2).size()<<endl;
    // cout<<s.generateTrees(3).size()<<endl;
    // cout<<s.generateTrees(4).size()<<endl;
    // cout<<s.generateTrees(5).size()<<endl;
    auto res = s.generateTrees(5);
    cout<<res.size()<<endl;
    for(auto tree: res){
        tree->show();
        cout<<endl;
    }
    return 0;
}
