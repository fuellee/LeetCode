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
    ListNode *sortList(ListNode *head) {
        if(head==nullptr) return head;
        vector<int> v;
        auto cur=head;
        for(cur=head; cur; cur=cur->next) v.push_back(cur->val);
        sort(v.begin(),v.end());
        cur = head;
        for(auto &val : v) {
           cur->val = val; 
           cur=cur->next;
        }
        return head;
    }
};
int main() {
    
    return 0;
}
