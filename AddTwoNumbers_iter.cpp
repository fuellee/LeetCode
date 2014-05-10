#include <iostream>
// Definition for singly-linked list.
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* next=nullptr) : val(x), next(next) {}
    void show() {
        if(this->next!=nullptr){
            cout<<this->val<<"->"; 
            this->next->show();
        }
        else 
            cout<<this->val<<endl;
    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dumy = new ListNode(0);
        ListNode *cur = dumy;
        int val=0,c=0;
        while(!(l1==nullptr && l2==nullptr)){
            if(l1==nullptr){
                val = l2->val + c;

                c = val/10;
                val = val%10;
                cur = cur->next = new ListNode(val);

                l2 = l2->next;
            } 
            else if(l2==nullptr){
                val = l1->val + c;

                c = val/10;
                val = val%10;
                cur = cur->next = new ListNode(val);

                l1 = l1->next;
            } 
            else {
                val = l1->val + l2->val + c;

                c = val/10;
                val = val%10;
                cur = cur->next = new ListNode(val);

                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if(c==1)
            cur->next=new ListNode(1);
        return dumy->next;
    }
};

int main() {
    #define N new ListNode
    Solution s;
    ListNode *l1 = N(2,N(4,N(3)));
    ListNode *l2 = N(5,N(6,N(4)));
    s.addTwoNumbers(l1,l2)->show();
    l1 = N(5);
    l2 = N(5);
    s.addTwoNumbers(l1,l2)->show();
    l1 = N(9,N(8));
    l2 = N(1);
    s.addTwoNumbers(l1,l2)->show();
    l1 = N(1,N(8));
    l2 = N(0);
    s.addTwoNumbers(l1,l2)->show();
    return 0;
}
