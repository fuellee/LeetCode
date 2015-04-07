/*
 * Reverse_Linked_List_II.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include "ListNode.hpp"
using namespace std;

class Solution {
public:
    int len(const ListNode *head) {
        int l=0;
        for(const ListNode *cur=head; cur; cur=cur->next) l++;
        return l;
    }
    ListNode *reverseFrom(ListNode *head, int n) { // n: num of nodes need to be reversed
        ListNode *pre=nullptr,*cur=head,*next;
        while(n-- && cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = next;
        return pre;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        int l= len(head);
        if(l<k) return head;
        ListNode *newhead=nullptr, *pre=nullptr;
        for(int i=0; i<l/k; ++i) {
            auto h=reverseFrom(head,k);
            if(newhead==nullptr) newhead = h;
            if(pre!=nullptr) pre->next = h; // pre:tail of last Group
            pre = head;
            head = head->next;
        }
        return newhead;
    }
};

int main() {
    #define N new ListNode
    Solution s;
    auto l0 = nullptr;
    cout<<"len:"<<s.len(l0)<<endl;
    s.reverseKGroup(l0,2)->show();

    auto l1 = N(1);
    cout<<"len:"<<s.len(l1)<<endl;
    s.reverseKGroup(l1,2)->show();

    auto l2 = N(1,N(2));
    cout<<"len:"<<s.len(l2)<<endl;
    s.reverseKGroup(l2,2)->show();

    auto l = N(1,N(2,N(3,N(4,N(5)))));
    cout<<"len:"<<s.len(l)<<endl;
    s.reverseKGroup(l,2)->show();

    auto l64 = N(1,N(2,N(3,N(4,N(5,N(6))))));
    cout<<"len:"<<s.len(l64)<<endl;
    s.reverseKGroup(l64,4)->show();

    auto l6 = N(1,N(2,N(3,N(4,N(5,N(6))))));
    cout<<"len:"<<s.len(l6)<<endl;
    s.reverseKGroup(l6,2)->show();

    return 0;
}
