#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *dumy = new ListNode(0);
public:
    ListNode *deleteDuplicates(ListNode *head) {
       if(head==nullptr) return head;
       dumy->next = head;
       ListNode *pre = dumy, *cur = head;
       int preval;
       while(cur->next != nullptr){
            if(cur->next->val==cur->val){

            }
       }
    }
};
