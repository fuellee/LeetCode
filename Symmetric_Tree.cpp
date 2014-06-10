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
    bool areSymmetric(TreeNode *t1, TreeNode *t2){
        if(t1==NULL && t2==NULL) return true;
        else if(t1==NULL || t2==NULL) return false;
        else if(t1->val != t2->val) return false;
        else return areSymmetric(t1->right,t2->left) and areSymmetric(t1->left,t2->right);
    }
public:
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        else return areSymmetric(root->left, root->right);
    }
};
