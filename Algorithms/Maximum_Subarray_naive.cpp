/*
 * Maximum_Subarray.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int *begin = A, *end=A+n, maxSum=INT_MIN;
        for(auto it=begin; it!=end; ++it) {
            if(*it>0) {
                int s=0;
                for(auto last=it; last!=end; ++last) {
                    s += *last;
                    maxSum = max(maxSum,s);
                }
            }
        }
        return maxSum;
    }
};
int main() {
    Solution s;
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(A,sizeof(A)/sizeof(int))<<endl;
    return 0;
}
