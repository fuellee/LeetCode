/*
 * Gray_Code.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n<=0) return {0};
        vector<int> res = {0,1};
        for(int i = 1; i < n; ++i) {
           int MSB = 1<<i;
           for(int j=res.size()-1; j>=0; --j)
               res.push_back(res[j]+MSB);
        }
        return res;
    }
};
