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
        constexpr int c_=3;
        int count[c_]={0};
        for(int i = 0; i < n; ++i)
            count[A[i]]++;

        int i = 0;
        for(int c=0; c<c_; c++){
            while(count[c]--)
                A[i++]=c;
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
