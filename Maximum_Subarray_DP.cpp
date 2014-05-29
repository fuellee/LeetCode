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
        int sumFromBegin=0,minSum=0,maxSum=INT_MIN;
        for(int i=0; i<n; ++i) {
            sumFromBegin+=A[i];
            int s = sumFromBegin - minSum;
            maxSum = max(maxSum, s);
            minSum = min(minSum, sumFromBegin);
        }
        return maxSum;
    }
};
int main() {
    Solution s;
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(A,sizeof(A)/sizeof(int))<<endl;
    int A1[] = {-1};
    cout<<s.maxSubArray(A1,sizeof(A1)/sizeof(int))<<endl;
    int A2[] = {-1,-2};
    cout<<s.maxSubArray(A2,sizeof(A2)/sizeof(int))<<endl;
    return 0;
}
