/*
 * 4Sum.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <FooBee/out>
using namespace std;

// generalized from 2-sum(2 for-loop), 3-sum(3 for-loop) and 4-sum(4 for-loop) to N-sum(recursion)
// slower than expanded for-loops
// passed threeSum
// TLE for fourSum

class Solution {
    vector<vector<int> > res;
public:
    void N_Sum(vector<int> &num, const int n, const int target) {
        const int numLen = num.size();
        // if(numLen<n) return {};
        if(numLen<n) return;
        sort(num.begin(),num.end());
        const int Min = num[0];
        const int Max = num.back();
        vector<vector<int> > &res=this->res;
        vector<int> acc(n);
        function<void(int,int,int)> nSum = 
            [&num,&acc,&n,&numLen,&Min,&Max,&res,&nSum]
            (int start, int len, int target) {
                if(len==n) {
                    if(target==0) res.push_back(acc);
                    return;
                }
                else if(start>=numLen || (n-len)*Min>target || (n-len)*Max<target) return;
                else {
                    for(int i=start; i<numLen-(n-len); i++)
                        if(i==start || num[i]!=num[i-1]) {
                            acc[len]=num[i];
                            nSum(i+1,len+1,target-num[i]);
                        }
                }
            };

        nSum(0,0,target);
        // return res;
    } 

    vector<vector<int> > threeSum(vector<int> &num) {
        res.clear();
        N_Sum(num,3,0);
        return res;
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        res.clear();
        N_Sum(num,4,target);
        return res;
    }
};
int main() {
    Solution s;
    vector<int> num {1,0,-1,0,-2,2};
    // cout<<s.threeSum(num)<<endl;
    cout<<s.fourSum(num, 0)<<endl;
    vector<int> num2 {-1,-5,-5,-3,2,5,0,4};
    // cout<<s.threeSum(num2)<<endl;
    cout<<s.fourSum(num2, -7)<<endl;
    vector<int> num3 {1,1,1,1,1,1,2,2};
    // cout<<s.threeSum(num3)<<endl;
    cout<<s.fourSum(num3, 5)<<endl;

    return 0;
}
