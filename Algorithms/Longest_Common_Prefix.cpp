/*
 * Longest_Common_Prefix.cpp
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
    string longestCommonPrefix(vector<string> &strs) {
        int N = strs.size();
        if(N==0) return "";
        else if(N==1) return strs[0];
        else {
            size_t minLen = accumulate(strs.begin()+1,strs.end(),strs[0].size(),
                                       [](size_t acc,string r){return min(acc,r.size());});
            for(size_t i=0; i<minLen; i++)
                for(auto &s: strs)
                    if(s[i]!=strs[0][i])
                        return strs[0].substr(0,i);
            return strs[0].substr(0,minLen);
        }
    }
};
