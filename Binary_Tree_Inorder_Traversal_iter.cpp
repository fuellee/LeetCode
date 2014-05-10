#include <vector>
#include <iostream>
#include <stack>
#include <functional>
using namespace std;
// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode *left=nullptr, TreeNode *right=nullptr) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if(root==nullptr) return {};
        vector<int> res;
        stack<TreeNode*> S_Nptr;
        stack<bool> S_flag; // false: haven't seen; true: seen
        S_Nptr.push(root);
        S_flag.push(false);
        while(!S_Nptr.empty()) {
            TreeNode *cur = S_Nptr.top(); 
            if(S_flag.top()) {//seen
                S_Nptr.pop();
                S_flag.pop();
                res.push_back(cur->val);
                if(cur->right) {
                    S_Nptr.push(cur->right);
                    S_flag.push(false);
                }
            }
            else { // haven't seen
               S_flag.top()=true; 
               if(cur->left) {
                   S_Nptr.push(S_Nptr.top()->left);
                   S_flag.push(false);
               }   
            }
        }
        return res;
    }
};

int main() {
    #define N new TreeNode
    TreeNode *tree = N(1,
                       nullptr,
                       N(2,
                         N(3)));
    Solution s;
    for(auto i:s.inorderTraversal(tree)) 
        cout<<i<<" ";
    return 0;
}
