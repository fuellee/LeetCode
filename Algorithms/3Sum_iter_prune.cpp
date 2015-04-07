/*
 * 4Sum.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <algorithm>
#include <FooBee/out>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if(num.size()<3) return {};
        sort(num.begin(),num.end());
        vector<vector<int> > res;
        const int N = num.size();
        const int Min = num[0];
        const int Max = num.back();
        for(int i1=0; i1<N-2; i1++){
            if(i1!=0 && num[i1]==num[i1-1]) continue; // guard for duplicates

            int S1=num[i1];
            if(S1+Max*2<0) continue; // prune
            if(S1+Min*2>0) break; 

            for(int i2=i1+1; i2<N-1; i2++){
                if(i2!=i1+1 && num[i2]==num[i2-1]) continue; // guard for duplicates

                int S2=S1+num[i2];
                if(S2+Max<0) continue; // prune
                if(S2+Min>0) break;

                for(int i3=i2+1; i3<N; i3++)
                    if(i3!=i2+1 && num[i3]==num[i3-1]) continue;  // guard for duplicates
                    else if(S2+num[i3]==0) res.push_back({num[i1],num[i2],num[i3]}); 
            } 
        } 
        return res;
    } 
};
int main() {
    Solution s;
    vector<int> num {1,0,-1,0,-2,2};
    cout<<s.threeSum(num)<<endl;
    vector<int> num2 {-1,-5,-5,-3,2,5,0,4};
    cout<<s.threeSum(num2)<<endl;
    vector<int> num3 {1,1,1,1,1,1,2,2};
    cout<<s.threeSum(num3)<<endl;

    return 0;
}
