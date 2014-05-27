#include <iostream>
#include "ListNode.hpp"
using namespace std;
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {        
        if(head==nullptr) return head;
        ListNode *dumy = new ListNode(0); dumy->next=head;
        ListNode *fast=dumy,*slow=dumy;
        while(n--) fast=fast->next;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }

        fast = slow->next;
        slow->next=slow->next->next;
        delete fast;

        return dumy->next;
    }
};

int main() {
    #define N new ListNode
    Solution s;
    ListNode *l = N(1,N(2,N(3,N(4,N(5)))));
    l->show();
    
    ListNode *newl = s.removeNthFromEnd(l,2);

    newl->show();
    return 0;
}
