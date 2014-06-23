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

// hahahaha!! runs slower than python (`4Sum_hash.py`)!
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        const int N = num.size();
        if(N<4) return {};
        sort(num.begin(),num.end());
        set<vector<int> > res;
        unordered_map<int,vector<pair<int,int> > > sum2Pair;
        
        for (int i1=0; i1<N-3; ++i1)
            for (int i2=i1+1; i2<N-2; ++i2)
                sum2Pair[num[i1]+num[i2]].push_back({i1,i2});

        for (int i3=2; i3<N-1; ++i3)
            for (int i4=i3+1; i4<N; ++i4) {
                int sum12 = target-num[i3]-num[i4];
                if(sum2Pair.find(sum12)!=sum2Pair.end()) {
                    for(auto &p12 : sum2Pair[sum12]) {
                        int &i1=p12.first, &i2=p12.second;
                        if(i2<i3) 
                            res.insert({num[i1],num[i2],num[i3],num[i4]});
                    }
                }
            }

        // convert set to vector
        vector<vector<int> > resvec(res.size());
        copy(res.begin(),res.end(),resvec.begin());
        return resvec;
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
