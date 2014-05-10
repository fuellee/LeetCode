/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void postorderTraversal(TreeNode *root, vector<int> &result){
        if(root==NULL) return;
        postorderTraversal(root->left, result);
        postorderTraversal(root->right, result);
        result.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }
};
