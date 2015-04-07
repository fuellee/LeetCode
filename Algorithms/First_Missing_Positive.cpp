/*
 * First_Missing_Positive.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include "print.hpp" 
#include <climits>
using namespace std;
class Solution {
public:
    // some kind like disjoint set
    int firstMissingPositive(int A[], int n) {
        if(n==0) return 1;
        int i=0;
        // pass 1: move each element to its position (n in A[n-1])
        while(i<n) 
            if(A[i]>=1 && A[i]<=n && A[A[i]-1]!=A[i])
                swap(A[A[i]-1],A[i]);
            else ++i;

        // pass 2: find the element in the wrong place
        for(i=0;i<=n && A[i]==i+1;i++);
        return i+1;
    }
};
int main() {
    Solution s;
    int A1[] = {3,4,-1,1};
    cout<<s.firstMissingPositive(A1,4)<<endl;
    int A2[] = {-1,4,2,1,9,10};
    cout<<s.firstMissingPositive(A2,6)<<endl;
    int A3[] = {3,2,1};
    cout<<s.firstMissingPositive(A3,3)<<endl;
    int A4[] = {3,2,1,2};
    cout<<s.firstMissingPositive(A4,4)<<endl;
    return 0;
}
