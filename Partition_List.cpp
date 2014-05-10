#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x,ListNode *next) : val(x), next(next) {}
    void show(){
        ListNode *cur=this;
        if(cur==nullptr) return;
        while(cur->next!=nullptr){
            cout<<cur->val<<"->";
            cur=cur->next;
        }
        cout<<cur->val<<endl;
    }
};
class Solution {
    ListNode* lessDumyHead = new ListNode(0);
    ListNode* moreDumyHead = new ListNode(0);
    void partition(ListNode *head, int pivot,ListNode* &less, ListNode* &more) {
        ListNode *lessCur=lessDumyHead,*moreCur=moreDumyHead,*cur=head;
        while(cur!=nullptr){
            if(cur->val<pivot){
               lessCur->next = cur;
               cur=cur->next;
               lessCur=lessCur->next;
               lessCur->next=nullptr;
            }
            else {
               moreCur->next = cur;
               cur=cur->next;
               moreCur=moreCur->next;
               moreCur->next=nullptr;
            }
        }
        less = lessDumyHead->next;
        more = moreDumyHead->next;
    }
    ListNode* &Tail(ListNode* &head) {
        if(head==nullptr) return head;
        else {
            ListNode *cur=head;
            while(cur->next!=nullptr)
               cur=cur->next; 
            return cur->next;
        }
    }
public:
    ListNode *partition(ListNode *head, int x) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* less, *more;
        partition(head,x,less,more);
        Tail(less) = more;
        return less;
    }
};
int main() {
    // vector<int> v={1,2,3};
    // vector<int> v={9};
    // for(auto i: plusOne(v))
    //     cout<<i<<" ";
    // sqrt(3);
    #define N new ListNode
    ListNode *list = N(1,N(2,N(4,N(3))));
    // list->show();
    Solution s;
    // s.Tail(list)=N(5);
    // s.Tail(list)=N(0);
    // list->show();
    // ListNode *less,*more;
    // s.partition(list,3,less,more);
    // less->show();
    // more->show();
    
    // list = N(1,N(2,N(3,N(4))));
    // list = N(5,N(3,N(4)));
    list = N(1,N(4,N(3,N(2,N(5,N(2))))));
    list->show();

    ListNode *parted = s.partition(list,3);
    parted->show();
    return 0;
}
