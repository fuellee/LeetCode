/*
 * Swap_Node_in_Pairs.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include "ListNode.hpp"
using namespace std;
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dumyHead(0);dumyHead.next=head;
        ListNode *pre=&dumyHead,*fst,*snd;
        while(pre->next) {
            fst = pre->next;
            snd = fst->next; if(snd==nullptr) break;

            fst->next = snd->next;
            snd->next = fst;

            pre->next = snd;
            pre = fst;
        }
        return dumyHead.next;
    }
};
int main() {
    Solution s; 
    #define N new ListNode
    auto l1 = N(1,N(2));
    cout<<*l1;
    s.swapPairs(l1)->show();

    cout<<"---------------------\n";
    auto l2 = N(1,N(2,N(3)));
    cout<<*l2;
    s.swapPairs(l2)->show();
    cout<<"---------------------\n";
    auto l4 = N(1,N(2,N(3,N(4))));
    cout<<*l4;
    s.swapPairs(l4)->show();
    return 0;
}
