/*
 * 4Sum_hash.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <algorithm>
#include <FooBee/out>
using namespace std;

// run fast!
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        const int N = num.size();
        if(N<4) return {};
        sort(num.begin(),num.end());
        const int Min = num[0];
        const int Max = num.back();
        vector<vector<int> > res;
        map<int,vector<pair<int,int> > > sum2Pair;
        
        // for all uniq pair of nums (i,j), collect two-sum
        for (int i=0; i<N-1; ++i) {
            int S1=num[i];
            if(S1+Max*3<target) continue; // prune
            if(S1+Min*3>target) break; 

            for (int j=i+1; j<N; ++j) {
                if(j!=i+1 and num[j]==num[j-1]) continue;

                int S2=S1+num[j];
                if(S2+Max*2<target) continue; // prune
                if(S2+Min*2>target) break;

                sum2Pair[S2].push_back({i,j});
            }
        }
        // cout<<sum2Pair<<endl;
        if(sum2Pair.size()==0) return {};

        // do two-sum on two-sums
        auto L=sum2Pair.begin(), R=sum2Pair.end(); R--;
        while(L!=R){
            int sum4 = L->first+R->first;
            if(sum4==target) {
                for(auto &p12: L->second) {
                    int i1=p12.first, i2=p12.second;
                    if(i1!=0 and num[i1]==num[i1-1])  continue;
                    for(auto &p34: R->second) {
                        int i3=p34.first, i4=p34.second;
                        if(i2<i3) { /* valid quadruplet */
                            if(i3!=i2+1 and num[i3]==num[i3-1]) continue;
                            res.push_back({num[i1],num[i2],num[i3],num[i4]});
                        }
                    }
                }
                L++;
                if(L==R) break;
                R--;
            }
            else if(sum4<target) L++;
            else R--;
        }
        if(L==R && 2*L->first==target) {
            for(auto &p12: L->second) {
                int i1=p12.first, i2=p12.second;
                if(i1!=0 and num[i1]==num[i1-1])  continue;
                for(auto &p34: R->second) {
                    int i3=p34.first, i4=p34.second;
                    if(i2<i3) {/* valid quadruplet */
                        if(i3!=i2+1 and num[i3]==num[i3-1]) continue;
                        res.push_back({num[i1],num[i2],num[i3],num[i4]});
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
    vector<int> num1 {-3,-2,-1,0,0,1,2,3};
    cout<<s.fourSum(num1, 0)<<endl;
    vector<int> num2 {-1,-5,-5,-3,2,5,0,4};
    cout<<s.fourSum(num2, -7)<<endl;
    vector<int> num3 {1,1,1,1,1,1,2,2};
    cout<<s.fourSum(num3, 5)<<endl;
    vector<int> num4 {0,0,0,0};
    cout<<s.fourSum(num4, 0)<<endl;
    cout<<s.fourSum(num4, 1)<<endl;

    return 0;
}
