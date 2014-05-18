#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next=nullptr) : val(x), next(next) {}
};

class Solution {
    ListNode *dumy = new ListNode(0);
public:
    ListNode *deleteDuplicates(ListNode *head) {
       if(head==nullptr) return head;
       bool inDuplicates=false;
       dumy->next = head;
       ListNode *pre = dumy, *cur = head;
       int val=
       while(cur->next != nullptr){
            if(cur->next->val==cur->val){

            }
       }
    }
};
