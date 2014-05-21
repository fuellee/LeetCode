/*
 * Minimum_Path_Sum.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int rowN=grid.size();
        if(rowN==0) return 0;
        int colN=grid[0].size();
        for (int col = 1; col < colN; ++col) 
            grid[0][col]+=grid[0][col-1];
        for (int row = 1; row < rowN; ++row) {
            for (int col = 0; col < colN; ++col) {
                // int preCol = (col==0)? INT_MAX:grid[row][col-1];
                // grid[row][col]+=min(preCol,grid[row-1][col]);
                if(col>0)
                    grid[row][col]+=min(grid[row][col-1],grid[row-1][col]);
                else
                    grid[row][col]+=grid[row-1][col];
            }
        }
        return grid[rowN-1][colN-1];
    }
};

int main() {
    Solution s;
    vector<vector<int> > grid1 {{1,2},{1,1}};
    vector<vector<int> > grid2 {{1,3,1},{1,5,1},{4,2,1}};
    cout<<s.minPathSum(grid1)<<endl;
    cout<<s.minPathSum(grid2)<<endl;
    for(auto row: grid1){
        for(auto e: row)
            cout<<e<<" ";
        cout<<endl;
    }
    for(auto row: grid2){
        for(auto e: row)
            cout<<e<<" ";
        cout<<endl;
    }
    return 0;
}
