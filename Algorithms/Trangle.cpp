/*
 * Trangle.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int rowN = triangle.size();
        if(rowN==0) return 0;
        vector<int> DP=triangle.back();
        for (int row =rowN-2;row >= 0; --row) {
            for (int col = 0;col<=row; ++col) {
                DP[col]=triangle[row][col] + min(DP[col],DP[col+1]);
            }
        }
        return DP[0];
    }
};
int main() {
    Solution s;
    vector<vector<int> > triangle {{2},
                                   {3,4},
                                   {6,5,7},
                                   {4,1,8,3}};
    cout<<s.minimumTotal(triangle)<<endl;
    return 0;
}
