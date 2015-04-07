/*
 * Reorder_List.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include "print.hpp"
#include "ListNode.hpp"
using namespace std;


class Solution {
public:
    ListNode *reverse(ListNode *head) {
        ListNode *cur=head, *pre=nullptr;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
    void reorderList(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return;
        ListNode *fast=head,*slow=head;
        // partition
        for(;fast && fast->next && fast->next->next; slow=slow->next, fast=fast->next->next);
        
        // reverse the second half
        ListNode *hd[2] = {head,reverse(slow->next)};
        slow->next=nullptr;
        
        // merge
        ListNode *cur = new ListNode(0);
        for(int i=0; cur && hd[i%2]; i++) {
            cur = cur->next = hd[i%2];
            hd[i%2] = hd[i%2]->next;
        }
    }
};
int main() {
    Solution s;    
    #define N new ListNode
    // auto l2 = N(1,N(2));
    // s.reverse(l2)->show();
    auto l0 = N(1,N(2,N(3,N(4))));
    // s.reverse(l0)->show();
    s.reorderList(l0);
    l0->show();
    cout<<*l0;
    auto l = N(1,N(2,N(3,N(4,N(5)))));
    // // s.reverse(l)->show();
    s.reorderList(l);
    l->show();
    return 0;
}
