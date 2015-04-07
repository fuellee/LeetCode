/*
 * ListNode.hpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef LISTNODE_HPP
#define LISTNODE_HPP

/*
 * Reorder_List.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next=nullptr) : val(x), next(next) {}
    void show(std::ostream &out=std::cout) const {
        if(this==nullptr) {
            out<<"|\n";
            return;
        }
        if(this->next!=nullptr){
            std::cout<<this->val<<"->"; 
            this->next->show();
        }
        else std::cout<<this->val<<std::endl;
    }
};

std::ostream & operator<<(std::ostream &out, const ListNode &lst){
    lst.show(out); 
    return out;
}
#endif /* !LISTNODE_HPP */
