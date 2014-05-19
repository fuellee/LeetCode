/*
 * Remove_Duplicates_from_Sorted_Array_II.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2) return n;

        int i=1,j;
        for(j=i+1;j<n;++j){
            if(!(A[j]==A[i] && A[j]==A[i-1]))
                A[++i]=A[j];
        }
        return i+1;
    }
};
int main() {
    Solution s;    
    int A[] = {1,1,1,2,2,3};
    int n = s.removeDuplicates(A,sizeof(A)/sizeof(int));
    cout<<"n="<<n<<endl;
    for (int i = 0; i < n; ++i)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
