/*
 * 4Sum_2Points_dupGuard.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

// combine `4Sum_iter_prune.cpp` and `Two_Sum_2Points_dupGuard.cpp`
// use Two_sum linear scan instead of 2-level of for-loops
// generalized from `3Sum_2Points_dupGuard.cpp`
#include <iostream>
#include <algorithm>
#include <FooBee/out>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if(num.size()<4) return {};
        sort(num.begin(),num.end());
        vector<vector<int> > res;
        const int N = num.size();
        const int Min = num[0];
        const int Max = num.back();
        for(int i1=0; i1<N-3; i1++){
            if(i1!=0 && num[i1]==num[i1-1]) continue; // guard for duplicates

            int S1=num[i1];
            if(S1+Max*3<target) continue; // prune
            if(S1+Min*3>target) break; 

            for(int i2=i1+1; i2<N-2; i2++){
                if(i2!=i1+1 && num[i2]==num[i2-1]) continue; // guard for duplicates

                int S2=S1+num[i2];
                if(S2+Max*2<target) continue; // prune
                if(S2+Min*2>target) break;

                int L=i2+1, R=N-1;
                while (L < R) {
                    if(L!=i2+1 && num[L]==num[L-1]){ // guard for duplicates (L)
                        L++;
                        continue; 
                    } 
                    if(R!=N-1 && num[R]==num[R+1]){ // guard for duplicates (R)
                        R--;
                        continue; 
                    }
                    int sum4 = S2+num[L]+num[R];
                    if (sum4 < target) L++;
                    else if (sum4 > target) R--;
                    else {
                        res.push_back({num[i1],num[i2],num[L],num[R]});
                        L++;
                        R--;
                    }
                }
            } 
        } 
        return res;
    }
};

int main() {
    Solution s;
    vector<int> num {1,0,-1,0,-2,2};
    cout<<s.fourSum(num, 0)<<endl;
    vector<int> num2 {-1,-5,-5,-3,2,5,0,4};
    cout<<s.fourSum(num2, -7)<<endl;
    vector<int> num3 {1,1,1,1,1,1,2,2};
    cout<<s.fourSum(num3, 5)<<endl;

    return 0;
}
