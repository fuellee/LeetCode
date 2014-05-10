#include <vector>
#include <stack>
#include <functional>
using namespace std;
// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if(root==nullptr) return {};
        vector<int> res;
        stack<TreeNode*> S;
        S.push(root);
        while(!S.empty()) {
            TreeNode *cur = S.top(); S.pop();
            res.push_back(cur->val);
            if(cur->right) S.push(cur->right);
            if(cur->left)  S.push(cur->left);
        }
        return res;
    }
};
