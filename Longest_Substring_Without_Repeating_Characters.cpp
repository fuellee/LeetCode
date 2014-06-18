/*
 * Longest_Substring_Without_Repeating_Characters.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */
// 奇迹！居然一次就AC！哇哈哈哈
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> subs;
        size_t L=0, maxSubsLen=0;
        for(size_t R=L; R<s.size(); R++) {
            if(subs.find(s[R])!=subs.end()) { // s[R] is repeated
                for(; L<s.size() && s[L]!=s[R]; L++)
                    subs.erase(s[L]);
                L++; // point to the first element that is not equal to s[R]
            }
            else 
                maxSubsLen = max(maxSubsLen,R-L+1);

            subs.insert(s[R]);
        }
        return maxSubsLen;
    }
};
