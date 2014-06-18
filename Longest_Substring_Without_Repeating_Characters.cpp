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
        const size_t len = s.size();
        if(len<=1) 
            return len;

        set<char> subs;
        size_t L=0,offset=0, maxOffset=1;
        for(size_t R=L; R<len; R++) {
            subs.insert(s[R]);
            if(subs.size()<offset+1) {
                for(; L<len && s[L]!=s[R]; L++) {
                    subs.erase(s[L]);
                }
                if(L!=R) {
                    L++; // point to the first element that is not equal to s[R]
                }
                offset = R-L+1;
            }
            else {
                offset++;
                maxOffset = max(maxOffset,offset);
            }
        }
        return maxOffset;
    }
};
