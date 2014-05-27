#include <iostream>
#include "ListNode.hpp"
using namespace std;

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return head;
        else {
            auto dumy = new ListNode(0);
            dumy->next = head;
            ListNode *preNewEnd=dumy,*curr=dumy;
            while(curr->next){
                if(preNewEnd->next->val!=curr->val){
                    cout<<preNewEnd->val;
                    preNewEnd->next=curr;
                    preNewEnd = preNewEnd->next;
                }
                curr = curr->next;
            }
            return dumy->next;
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
