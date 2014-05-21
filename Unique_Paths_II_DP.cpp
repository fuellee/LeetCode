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
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        // DP[row][col] = DP[row-1][col]+ DP[row][col-1];
        // with state compress
        // DP[col] = DP[col-1] + DP[col]
        vector<int> DP(n,0);
        DP[0]=1;
        for (int row = 0; row < m; ++row)
            for (int col = 0; col < n; ++col) {
                if(obstacleGrid[row][col]) DP[col]=0;
                else if(col>0) // col-1 can't be -1
                    DP[col]+=DP[col-1];
            }
        return DP[n-1];
    }
};
int main() {
    Solution s;
    vector<vector<int> > obstacleGrid1 {{0,0,0},
                                        {0,1,0},
                                        {0,0,0}};

    vector<vector<int> > obstacleGrid2 {{0,0},{1,0}};
    vector<vector<int> > obstacleGrid3 {{0}};
    cout<<(s.uniquePathsWithObstacles(obstacleGrid1)==2)<<endl;
    cout<<(s.uniquePathsWithObstacles(obstacleGrid2)==1)<<endl;
    cout<<(s.uniquePathsWithObstacles(obstacleGrid3)==1)<<endl;
    return 0;
}
