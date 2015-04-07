#include <iostream>
#include "ListNode.hpp"
// Definition for singly-linked list.
using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int c=0) {
        if(l1==nullptr && l2==nullptr)
            return (c==1)? new ListNode(1): nullptr;
        else if(l1==nullptr || l2==nullptr){
            ListNode *l=(l2==nullptr)? l1:l2;
            int val = l->val + c;

            c = val/10;
            val = val%10;
            ListNode *result = new ListNode(val);
            result->next = addTwoNumbers(nullptr, l->next, c);
            return result;
        } 
        else {
            int val = l1->val + l2->val + c;

            c = val/10;
            val = val%10;
            ListNode *result = new ListNode(val);
            result->next = addTwoNumbers(l1->next, l2->next, c);
            return result;
        }

    }
};

int main() {
    #define N new ListNode
    Solution s;
    ListNode *l1 = N(2,N(4,N(3)));
    ListNode *l2 = N(5,N(6,N(4)));
    s.addTwoNumbers(l1,l2)->show();
    l1 = N(5);
    l2 = N(5);
    s.addTwoNumbers(l1,l2)->show();
    l1 = N(9,N(8));
    l2 = N(1);
    s.addTwoNumbers(l1,l2)->show();
    l1 = N(1,N(8));
    l2 = N(0);
    s.addTwoNumbers(l1,l2)->show();
    return 0;
}
