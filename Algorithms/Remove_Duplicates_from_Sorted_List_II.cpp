#include <iostream>
#include "ListNode.hpp"
using namespace std;

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return head;
        else {
            ListNode dumy(0);  
            dumy.next = head;  
            ListNode *pre = &dumy, *cur = head;  
            while(cur!=nullptr)  {  
                bool isDup = false;  
                while(cur->next!=nullptr && cur->val == cur->next->val) {  
                    isDup = true;  
                    ListNode *tmp = cur;  
                    cur = cur->next;  
                    delete tmp;  
                }  
                if(isDup) {  
                    ListNode *tmp = cur;  
                    cur = cur->next;  
                    delete tmp;  
                    continue;  
                }  
                pre->next = cur;  
                pre = pre->next;  
                cur= cur->next;  
            }  
            pre->next = cur;  
            ListNode *tmp = dumy.next;  
            return tmp;     
        }
    }
};

int main() {
    Solution s;
    #define N new ListNode
    auto list = N(1,N(2));
    list->show();
    s.deleteDuplicates(list);
    return 0;
}
