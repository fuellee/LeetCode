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
    enum class state : char {Start, LBack, RBack};
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if(root==nullptr) return {};
        vector<int> res;
        stack<TreeNode*> S_Nptr;
        stack<state> S_flag;
        S_Nptr.push(root); S_flag.push(state::Start);
        while(!S_Nptr.empty()) {
            TreeNode *cur = S_Nptr.top(); 
            if(S_flag.top()==state::Start) {
                S_flag.top()=state::LBack; 
                if(cur->left) {S_Nptr.push(cur->left); S_flag.push(state::Start);}   
            }
            else if(S_flag.top()==state::LBack) {
                S_flag.top()=state::RBack; 
                if(cur->right) {S_Nptr.push(cur->right); S_flag.push(state::Start);}
            }
            else if(S_flag.top()==state::RBack) {
                res.push_back(cur->val);
                S_Nptr.pop(); S_flag.pop();
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
    for(auto i:s.postorderTraversal(tree)) 
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
