#include <iostream>
#include <map>
using namespace std;
// * Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==nullptr) return nullptr;
        map<RandomListNode*,RandomListNode*> old2new;
        RandomListNode *newhead=new RandomListNode(head->label);
        old2new[head]=newhead;
        RandomListNode *old_=head, *new_=newhead;
        while(old_ != nullptr){
            if(old_->next==nullptr)
                new_->next = nullptr;
            else if(old2new.find(old_->next)!=old2new.end())
                new_->next = old2new[old_->next];
            else{
                new_->next = new RandomListNode(old_->next->label);
                old2new[old_->next]=new_->next;
            }

            if(old_->random==nullptr)
                new_->random = nullptr;
            else if(old2new.find(old_->random)!=old2new.end())
                new_->random = old2new[old_->random];
            else{
                new_->random = new RandomListNode(old_->random->label);
                old2new[old_->random]=new_->random;
            }
            
            old_ = old_->next;
            new_ = new_->next;
        }

        return newhead;
    }
};

int main() {
    #define N new RandomListNode
    Solution s;
    s.copyRandomList(N(1));
    return 0;
}
