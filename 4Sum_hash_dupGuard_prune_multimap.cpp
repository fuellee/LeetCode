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

// run fast! but ugly! unordered_multimap makes code looks bad
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        const int N = num.size();
        if(N<4) return {};
        sort(num.begin(),num.end());
        const int Min = num[0];
        const int Max = num.back();
        vector<vector<int> > res;
        unordered_multimap<int,pair<int,int> > sum2Pair;

        for (int i1=0; i1<N-3; ++i1) {
            int S1=num[i1];
            if(S1+Max*3<target) continue; // prune
            if(S1+Min*3>target) break; 
            for (int i2=i1+1; i2<N-2; ++i2) {
                if(i2!=i1+1 and num[i2]==num[i2-1]) continue;

                int S2=S1+num[i2];
                if(S2+Max*2<target) continue; // prune
                if(S2+Min*2>target) break;

                sum2Pair.insert({S2,{i1,i2}});
            }
        }

        for (int i3=2; i3<N-1; ++i3)
            for (int i4=i3+1; i4<N; ++i4) {
                if(i4!=i3+1 and num[i4]==num[i4-1]) continue;
                int sum12 = target-num[i3]-num[i4];
                if(sum2Pair.find(sum12)!=sum2Pair.end()) {
                    auto range = sum2Pair.equal_range(sum12);
                    for_each(range.first, range.second,
                             [&num,&res,&i3,&i4] (pair<const int,pair<int,int> > &x) {
                                int &i1=x.second.first, &i2=x.second.second;
                                if(i1!=0 and num[i1]==num[i1-1]) return;
                                if(i2<i3) {
                                    if(i3!=i2+1 and num[i3]==num[i3-1]) return;
                                    res.push_back({num[i1],num[i2],num[i3],num[i4]});
                                }
                             });
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
