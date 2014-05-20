/*
 * Merge_Sorted_Array.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // merge from end to the begin in place
        for(int i=m+n-1,Ai=m-1,Bi=n-1; i>=0; i--) {
            if(Bi<0) break;
            else if(Ai<0) 
                A[i]=B[Bi--];
            else if(A[Ai]>B[Bi]) 
                A[i]=A[Ai--];
            else 
                A[i]=B[Bi--];
        }
    }
};
int main() {
    constexpr int m=2,n=1;
    int A[m+n] = {1,2,0};
    int B[n] = {1};
    Solution s;
    s.merge(A,2,B,1);
    for(int i=0;i<m+n; i++)
        cout<<"A["<<i<<"]="<<A[i]<<"\n";
    return 0;
}
