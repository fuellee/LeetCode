/*
 * Rotate_Image.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include "print.hpp"
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n=matrix.size();
        // matrix = matrix' (transpose)
        for(int r=0; r<n; ++r)
            for(int c=r; c<n; ++c)
                swap(matrix[r][c],matrix[c][r]);

        // mirror according to the middle coloumn
        for(int r=0; r<n; ++r)
            for(int c=0; c<n/2; ++c)
                swap(matrix[r][c],matrix[r][n-1-c]);
    }
};
int main() {
    Solution s;
    vector<vector<int> > matrix {{1,2},{3,4}};
    cout<<matrix<<endl;
    s.rotate(matrix);
    cout<<matrix<<endl;
    return 0;
}
