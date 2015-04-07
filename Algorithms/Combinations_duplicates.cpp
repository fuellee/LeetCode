/*
 * Combination_duplicates.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <FooBee/out>
using namespace std;

vector<vector<int> > combinations(vector<int> nums, int n) {
    int numsLen=nums.size();
    if(numsLen<n) return {};
    sort(nums.begin(),nums.end());
    vector<vector<int> > res;
    vector<int> acc(n);
    function<void(int,int)> com = 
        [&com,&res,&numsLen,&n,&acc,&nums]
        (int start, int len) {
            if(len==n) res.push_back(acc);
            else if(start>=numsLen) return;
            else 
                for(int i=start; i<numsLen; ++i) {
                    if(i==start || nums[i]!=nums[i-1]) {
                        acc[len]=nums[i];
                        com(i+1,len+1);
                    }
                }
        };
    com(0,0);
    return res;
}

int main() {
    cout<<combinations({1,1,2,2,3,4},3)<<endl;
    return 0;
}
