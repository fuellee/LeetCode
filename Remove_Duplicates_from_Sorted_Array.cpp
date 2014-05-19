/*
 * Remove_Duplicates_from_Sorted_Array.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=1) return n;
        int i=0,j; // i:last pos of new array; j:curr element;
        for(j=i+1;j<n;++j)
            if(A[i]!=A[j])
                A[++i]=A[j];

        return i+1;
    }
};
int main() {
    Solution s;    
    int A[] = {1,1,3,4};
    int n = s.removeDuplicates(A,sizeof(A)/sizeof(int));
    cout<<"n="<<n<<endl;
    for (int i = 0; i < n; ++i)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
