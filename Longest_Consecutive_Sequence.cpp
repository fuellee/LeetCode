/*
 * Longest_Consecutive_Sequence.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
// 1. create hashmap of num list
// 2. scan num vector, check wether its successors and previous is present in hashmap
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> S(num.begin(),num.end());
        int curlen=0,maxlen=0;
        for(auto &i:num) {
            if(S.find(i)!=S.end()) {
                S.erase(i);
                curlen = 1;
                for(int nxt=i+1; S.find(nxt)!=S.end(); nxt++) {
                    S.erase(nxt);
                    curlen++; 
                }
                for(int pre=i-1; S.find(pre)!=S.end(); pre--) {
                    S.erase(pre);
                    curlen++; 
                }
                maxlen = max(maxlen,curlen);
                if(S.empty()) break;
            }
        }
        return maxlen;
    }
};
