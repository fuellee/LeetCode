/*
 * Convert_Sorted_Array_to_Binary_Search_Tree.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *sortedListToBST(ListNode* &head,int len) {
        if(len==0) return nullptr;
        int mid = len/2;

        // left - subtree
        auto left = sortedListToBST(head,mid);

        // subtree - root
        auto root = new TreeNode(head->val);
        root->left = left;
        head = head->next;

        // right - subtree
        root->right = sortedListToBST(head, len-mid-1);
        return root;

    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len=0;
        for(auto cur=head;cur!=nullptr;cur=cur->next, ++len);
        return sortedListToBST(head, len);
    }
};
int main() {
    return 0;
}
