/*
 * Search_for_a_Range.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <algorithm>
#include <FooBee/out>
using namespace std;
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int* L = lower_bound(A,A+n,target);
        int* R = upper_bound(A,A+n,target);
        R--;
        if(L==A+n) return {-1,-1};
        else if(*L==target && *R==target) return {int(L-A),int(R-A)};
        else return {-1,-1};
    }
};
int main() {
    Solution s; 
    int A[] = {1};
    cout<<s.searchRange(A,1,1)<<endl;
    return 0;
}
