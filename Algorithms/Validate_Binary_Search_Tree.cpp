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
    TreeNode *pre=NULL;
public:
    bool isValidBST(TreeNode *root) {
        if(root==NULL) 
            return true;
        // left subtree
        if(! isValidBST(root->left))
            return false;
        // root
        if(pre!=NULL and pre->val>=root->val)
            return false;
        pre = root;
        // right subtree
        return isValidBST(root->right);
    }
};
