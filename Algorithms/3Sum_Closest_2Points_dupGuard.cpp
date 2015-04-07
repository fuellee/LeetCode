/*
 * 3Sum_Closest.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <FooBee/out>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int n = num.size();
        int Mindiff=INT_MAX, threeSum=num[0]+num[1]+num[2];
        for (int i = 0;i < n; i++) {
            if(i!=0 && num[i]==num[i-1]) continue;  // guard for duplicates (i)
            int L = i + 1;
            int R = n - 1;
            while (L < R) {
                if(L!=i+1 && num[L]==num[L-1]){ // guard for duplicates (L)
                    L++;
                    continue; 
                } 
                if(R!=n-1 && num[R]==num[R+1]){ // guard for duplicates (R)
                    R--;
                    continue; 
                }
                int S3 = num[i] + num[L] + num[R];
                int d = abs(target-S3);
                if(d<Mindiff) {
                    Mindiff = d;
                    threeSum = S3;
                }

                if (S3 < target) L++;
                else if (S3 > target) R--;
                else return target; // S3==target, closest
            }
        }
        return threeSum;
    }
};

int main() {
    Solution s;
    vector<int> num {1,0,-1,0,-2,2};
    cout<<s.threeSumClosest(num,0)<<endl;
    vector<int> num2 {-1,-5,-5,-3,2,5,0,4};
    cout<<s.threeSumClosest(num2,0)<<endl;
    vector<int> num3 {1,1,1,1,1,1,2,2};
    cout<<s.threeSumClosest(num3,0)<<endl;

    return 0;
}

