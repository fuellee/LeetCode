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
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        function<void(TreeNode*)> pt = [&pt,&res](TreeNode *root) {
            if(root==NULL) return;
            else {
                res.push_back(root->val);
                pt(root->left);
                pt(root->right);
            }
        };
        pt(root);
        return res;
    }
};
