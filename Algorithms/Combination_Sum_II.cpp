/*
 * Combination_Sum_II.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<int> > res;
    vector<int> num;
    int n;
// void comS(int start, vector<int> &acc, int target) {
//     if(target == 0) { // a solution
//         res.push_back(acc);
//         return;
//     }
//     else if(target<0 || start>=n) // prune
//         return;
//     else // branch
//         for(int i=start;i<n; i++) {
//             if(i>start && num[i]==num[i-1]) 
//                 continue;
//             acc.push_back(num[i]);
//             comS(i+1,acc,target-num[i]);
//             acc.pop_back();
//         }
// }

void comS(int start, vector<int> &acc, int target) {
    if(target==0) res.push_back(acc);
    else if (start>=n || target<0) return;
    else 
        for(int i=start; i<n; ++i) {
            if(i==start || num[i]!=num[i-1]) {
                acc.push_back(num[i]);
                comS(i+1, acc, target-num[i]);
                acc.pop_back();
            }
        }
}
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        res.clear();
        sort(num.begin(), num.end());
        this->num = num;
        n = num.size();
        vector<int> acc;
        comS(0,acc,target);
        return res;
    }
};

int main() {
    Solution s;
    // vector<int> S = {2,3,6,7};
    // auto res = s.combinationSum2(S,7);
    // vector<int> S = {10,1,2,7,6,1,5};
    // auto res = s.combinationSum2(S,8);
    vector<int> S = {1,1,1,1};
    auto res = s.combinationSum2(S,2);
    for(auto v:res){
        for(auto e:v)
            cout<<e<<" ";
        cout<<endl;
    }
    return 0;
}
