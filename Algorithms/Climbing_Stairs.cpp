/*
 * Climbing_Stairs.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // int climbStairs(int n) {
    //     if(n<=0) return 0;
    //     else if(n==0) return 1;
    //     else return climbStairs(n-1)+climbStairs(n-2);
    // }
    /*DP*/
    // int climbStairs(int n) {
    //     vector<int> DP(n+1,1);
    //     DP[1]=1;
    //     for(int i=2; i<=n; ++i) {
    //         DP[i]=DP[i-2]+DP[i-1];
    //     }
    //     return DP[n];
    // }
    /*DP with state compression*/
    int climbStairs(int n) {
        int DP1=1,DP2=1;
        for(int i=2; i<=n; ++i) {
            int DPn=DP1+DP2;
            DP1=DP2;
            DP2=DPn;
        }
        return DP2;
    }
};
int main() {
    Solution s; 
    for(int n : {0,1,2,3,4,5,6,7})
        cout<<s.climbStairs(n)<<endl;
    return 0;
}
