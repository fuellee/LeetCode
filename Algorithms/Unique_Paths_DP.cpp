/*
 * Unique_Paths.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        // DP[row][col] = DP[row-1][col]+ DP[row][col-1];
        // with state compress
        // DP[col] = DP[col-1] + DP[col]
        if(m>n) swap(m,n);
        // m<n
        vector<int> DP(n,1);
        for (int row = 1; row < m; ++row)
            for (int col = 1; col < n; ++col)
                DP[col]+=DP[col-1];
        return DP[n-1];
    }
};
int main() {
    Solution s;
    cout<<s.uniquePaths(3,7)<<endl;
    return 0;
}
