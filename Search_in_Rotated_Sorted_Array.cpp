/*
 * Search_in_Rotated_Sorted_Array.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
    int *A;
public:
    int search_(int A[], int n, int target) {
        // cout<<"n:"<<n<<endl;
        if(n==0) return -1;

        int L=0,R=n-1;        
        if(A[L]>A[R]) {
            int mid = (L+R)/2+1; // +1 to eliminate dead left call
            int Lpos=search_(A,mid,target);
            if(Lpos!=-1) return Lpos;
            return search_(A+mid,R-mid+1,target);
        }
        else {
            int *e = lower_bound(A,A+n,target);
            if(e==A+n || *e!=target) return -1;
            else return e-this->A;
        }
    }
    int search(int A[], int n, int target) {
        this->A = A;
        return search_(A,n,target);
    }
};
int main() {
    Solution s;
    int A[] = {3,1};
    cout<<s.search(A,2,0)<<endl;
    int A1[] = {1};
    cout<<s.search(A1,1,1)<<endl;
    return 0;
}
