/*
 * Search_a_2D_Matrix.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include "print.hpp"
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rowN = matrix.size();
        if(rowN==0) return false;

        auto rowIt =lower_bound(matrix.begin(),matrix.end(),vector<int>(1,target),
                             [](const vector<int> &l,const vector<int> &r){return l[0]<=r[0];});//`<=` skip target

        auto &row = (rowIt==matrix.begin())? *rowIt: *(rowIt-1);
        auto it = lower_bound(row.begin(),row.end(),target);

        if(it==row.end()) return false;
        else return *it==target;
    }
};

int main() {
    Solution s;
    vector<vector<int> > matrix {{1}};
    cout<<(s.searchMatrix(matrix,1)==1)<<endl;
    vector<vector<int> > matrix1 {{1,   2,  3,  4},
                                  {5,   6,  7,  8},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 50}};
    cout<<(s.searchMatrix(matrix1,5)==1)<<endl;
    vector<vector<int> > matrix2 {{1,1}};
    cout<<(s.searchMatrix(matrix2,0)==0)<<endl;
    vector<vector<int> > matrix3 {{1,3}};
    cout<<(s.searchMatrix(matrix3,2)==0)<<endl;
    vector<vector<int> > matrix4 {{1}};
    cout<<(s.searchMatrix(matrix4,0)==0)<<endl;
    
    return 0;
}
