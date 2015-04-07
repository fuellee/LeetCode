/*
 * 3Sum.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <FooBee/out>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        set<vector<int> > triplets;
        int n = num.size();
        for (int i = 0;i < n; i++) {
            int L = i + 1;
            int R = n - 1;
            int target = - num[i];
            while (L < R) {
                int sum_two = num[L] + num[R];
                if (sum_two < target) L++;
                else if (sum_two > target) R--;
                else {
                    triplets.insert({num[i],num[L],num[R]});
                    L++;
                    R--;
                }
            }
        }
        vector<vector<int> > res(triplets.size());
        copy(triplets.begin(), triplets.end(), res.begin());
        return res;
    }
};

int main() {
    Solution s;    
    vector<int> num {-1,0,1,2,-1,-4};
    cout<<s.threeSum(num)<<endl;
    vector<int> num1 {-1,0,0,1};
    cout<<s.threeSum(num1)<<endl;
    vector<int> num2 {1,2,-2,-1};
    cout<<s.threeSum(num2)<<endl;
    vector<int> num3 {-2,1,1};
    cout<<s.threeSum(num3)<<endl;
    vector<int> num4 {-2,0,0,0,1,1};
    cout<<s.threeSum(num4)<<endl;
    return 0;
}
