/*
 * Trapping_Rain_Water.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;
class Solution {
public:
    int trap(int A[], int n) {
        if(n<=1) return 0;
        int water=0,l=0,r=n-1;
        while(l<r){
            for(;l<=r && A[l]==0;l++);
            for(;l<=r && A[r]==0;r--);
            int barH=min(A[l],A[r]);
            int levelWater=0;
            // cout<<"l="<<l<<", r="<<r<<endl;
            // cout<<"barH="<<barH<<endl;
            // if(++l>--r) return water;
            for(int i=l;i<=r;i++){
                ////
                levelWater += max(0,barH-A[i]);
                A[i] = max(0,A[i]-barH);
            }
            // cout<<"levelWater="<<levelWater<<endl;
            // cout<<"==========================\n";
            // if(levelWater<=0) return water;
            water+=levelWater;
        }
        return water;
    }
};
int main() {
    Solution s;
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(A,sizeof(A)/sizeof(int))<<endl;
    int A2[] ={6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
    cout<<s.trap(A2,sizeof(A2)/sizeof(int))<<endl;
    int A3[] ={4,9,4,5,3,2};
    cout<<s.trap(A3,sizeof(A3)/sizeof(int))<<endl;
    return 0;
}
