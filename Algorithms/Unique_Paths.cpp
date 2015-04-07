/*
 * Unique_Paths.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;
class Solution {
    int C(int m,int n) {
        long long res=1;
        for (int i=1; i<=n; ++i,--m) {
            res*=m;
            res/=i;
        } 
        return res;
    }
public:
    int uniquePaths(int m, int n) {
        return C(m+n-2,min(m,n)-1);
    }
};
int main() {
    Solution s;
    cout<<s.uniquePaths(3,7)<<endl;
    return 0;
}
