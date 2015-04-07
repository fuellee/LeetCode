/*
 * Anagrams.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string,vector<string> > D;
        for(auto &s : strs) {
            string soredS = s;
            sort(soredS.begin(),soredS.end());
            D[soredS].push_back(s);
        }
        vector<string> res;
        for (auto &p : D) {
            if(p.second.size()>=2)
                res.insert(res.end(),p.second.begin(),p.second.end());
        }
        return res;
    }
};
