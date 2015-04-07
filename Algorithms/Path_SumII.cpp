#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int sum;
    void sumNumbers(TreeNode *root, int acc){
        if(root==nullptr) return;
        acc = acc*10 + root->val;
        if(root->left==nullptr && root->right==nullptr)
            sum+=acc;
        else{
            sumNumbers(root->left, acc);
            sumNumbers(root->right, acc);
        }
    }
public:
    int sumNumbers(TreeNode *root) {
        sum=0;
        sumNumbers(root, 0);
        return sum;
    }

    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL) return false;
        sum=sum-root->val;
        if(root->left==nullptr && root->right==nullptr)
            return sum==0;
        else
            return hasPathSum(root->left, sum) or hasPathSum(root->right, sum);
    }
    vector<vector<int> > pathes;
    void pathSum(TreeNode *root, int sum, vector<int> path) {
        if(root==NULL) return;
        sum=sum-root->val;
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(sum==0)
                pathes.push_back(path);
            return;
        }
        else{
            pathSum(root->left, sum, path);
            pathSum(root->right, sum, path);
            return;
        }
    }
    vector<vector<int> > &pathSum(TreeNode *root, int sum) {
        pathes.clear();
        pathSum(root,sum,{});
        return pathes;
    }
};

int main() {
    Solution s;
    #define N new TreeNode
    // TreeNode *tree = N(1,N(2),N(3));
    TreeNode *tree = N(1);
    cout<<s.hasPathSum(tree,1)<<endl;
    return 0;
}
