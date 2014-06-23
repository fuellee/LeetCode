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
        unordered_map<int,vector<pair<int,int> > > sum2Pair;
        
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

        vector<int> sum2s; sum2s.reserve(sum2Pair.size());
        for(auto &p: sum2Pair) sum2s.push_back(p.first);
        sort(sum2s.begin(),sum2s.end());

        // do two-sum on two-sums
        int L=0,R=sum2s.size()-1;
        while(L<=R){
            int sum4 = sum2s[L]+sum2s[R];
            if     (sum4<target) L++;
            else if(sum4>target) R--;
            else {
                for(auto &p12: sum2Pair[sum2s[L]]) {
                    const int i1=p12.first, i2=p12.second;
                    if(i1!=0 and num[i1]==num[i1-1])  continue;
                    for(auto &p34: sum2Pair[sum2s[R]]) {
                        const int i3=p34.first, i4=p34.second;
                        if(i2<i3) {/* valid quadruplet */
                            if(i3!=i2+1 and num[i3]==num[i3-1]) continue;
                            res.push_back({num[i1],num[i2],num[i3],num[i4]});
                        }
                    }
                }
                L++;R--;
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

    return 0;
}
