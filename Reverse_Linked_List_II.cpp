/*
 * Reverse_Linked_List_II.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next=NULL) : val(x), next(next) {}
    void show() {
        if(this==nullptr) {
            cout<<"|\n";
            return;
        }
        if(this->next!=nullptr){
            cout<<this->val<<"->"; 
            this->next->show();
        }
        else cout<<this->val<<endl;
    }
};

class Solution {
public:
    ListNode *reverseFrom(ListNode *head, int n) { // n: num of nodes need to be reversed
        ListNode *pre=nullptr,*cur=head,*next;
        while(n--){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = next;
        return pre;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *cur=head;
        if(m==1) return reverseFrom(head,n-m+1);
        else {
            for(int i=1; i<m-1; i++) cur=cur->next;
            cur->next = reverseFrom(cur->next,n-m+1);
            return head;
        }
    }
};
