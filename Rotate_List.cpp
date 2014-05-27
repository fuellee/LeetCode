/*
 * Rotate_List.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <stack>
using namespace std;
#include "ListNode.hpp"
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==nullptr || k==0) return head;
        ListNode *cur=head,*tail=head,*mid=head;
        int len;
        for(len=0; cur; ++len){
            tail=cur;
            cur=cur->next;
        } 
        k = k%len;

        for(int i=0; i<len-k-1; ++i)
            mid = mid->next;

        tail->next = head;
        head = mid->next;
        mid->next = nullptr;

        return head;
    }
};
int main() {
    #define N new ListNode
    Solution s;
    auto l1 = N(1,N(2,N(3,N(4,N(5)))));
    l1->show();
    s.rotateRight(l1,2)->show();
    cout<<"---------------------\n";
    auto l2 = N(1,N(2));
    l2->show();
    s.rotateRight(l2,3)->show();
    return 0;
}
