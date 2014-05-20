/*
 * Sort_Colors.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;
class Solution {
public:
    void sortColors(int A[], int n) {
        int p0=0,p1=n;
        for(int i=0;i<p1;) {
            if(A[i]==0){
                swap(A[i++],A[p0++]);
            }
            else if(A[i]==2){
                swap(A[i],A[--p1]);
            }
            else i++;
        }
    }
};
int main() {
    Solution s;
    constexpr int l=1;
    int A[l] = {0};
    s.sortColors(A,l);
    for(int i=0;i<l;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
