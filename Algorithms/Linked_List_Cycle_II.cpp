#include "ListNode.hpp"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr) return nullptr;
        ListNode *fast=head,*slow=head;
        do{
            fast=fast->next->next;
            slow=slow->next;
        }while(fast && fast->next && fast!=slow);
        if(fast==nullptr || fast->next==nullptr) return nullptr;
        
        slow = head;
        for(;fast!=slow;fast=fast->next,slow=slow->next);
        return fast;
    }
};
