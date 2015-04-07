/*
 * subsets.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res(1);
        sort(S.begin(),S.end());
        for(auto e : S){
            int n = res.size();
            for (int i = 0; i < n; ++i) {
                vector<int> l(res[i]);
                l.push_back(e);
                res.push_back(l);
            }
        }
        return res;
    }
};
