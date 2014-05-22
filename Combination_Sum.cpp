/*
 * Combination_Sum_tailcall_opt.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        int last = candidates.size()-1;
        function<void(int,vector<int>&,int)> comS = 
            [&candidates, &res, &last, &comS](int i,vector<int> acc,int target){
            if(target<0) return;
            if(target==0) res.push_back(acc);
            else if(i<=last){
                comS(i+1,acc,target);
                acc.push_back(candidates[i]);
                comS(i,acc,target-candidates[i]);
            }
        };
        vector<int> acc={};
        comS(0,acc,target);
        return res;
    }
};
int main() {
    Solution s;
    vector<int> S = {2,3,6,7};
    auto res = s.combinationSum(S,7);
    for(auto v:res){
        for(auto e:v)
            cout<<e<<" ";
        cout<<endl;
    }
    return 0;
}
