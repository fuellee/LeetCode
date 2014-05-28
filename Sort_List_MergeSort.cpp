/*
 * Sort_List.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "ListNode.hpp"
using namespace std;
class Solution {
public:
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *merged,*p;
        merged = new ListNode(0);
        p = merged;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            }else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        ListNode *left=(l1==nullptr)? l2:l1;
        if(left!=nullptr)
            p->next=left;
        return merged->next;
    }
    ListNode *MergeSort(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode *fast=head,*slow=head;
        for(;fast->next&&fast->next->next; fast=fast->next->next, slow=slow->next);
        fast = slow->next;
        slow->next=nullptr;

        return merge(MergeSort(head), MergeSort(fast));
    }
    ListNode *sortList(ListNode *head) {
        return MergeSort(head);
    }
};
int main() {
    Solution s;
    #define N new ListNode        
    auto l = N(1,N(2,N(3,N(4,N(5)))));
    cout<<*s.sortList(l);

    
    vector<int> v {1,3,3,1,3,1,3,3,2,3,2,2,1,1,1,3,2,2,1,1,2,2,2,3,3,1,1,2,2,2,1,2,1,1,2,3,3,2,2,3,2,3,2,2};
    ListNode head(0),*cur=&head;
    for(auto &val : v){
        cur->next = N(val);
        cur=cur->next;
    }
    cout<<*s.sortList(head.next);
    return 0;
}
