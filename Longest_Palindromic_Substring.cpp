/*
 * Longest_Palindromic_Substring.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;
// O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(size<=1) return s;
        size_t maxPalindromeLen = 1;
        size_t pos=0,n=1;
        for (int i = 0; i < size; ++i) {
            size_t palindromeLen = 1;
            int r=1;
            for(; i-r>=0 && i+r<size && s[i-r]==s[i+r]; r++);
            r--;
            palindromeLen = 2*r+1;
            if(palindromeLen>maxPalindromeLen) {
                maxPalindromeLen = palindromeLen;
                pos = i-r;
                n = maxPalindromeLen;
            }

            int L=i,R=i+1;
            for(; L>=0 && R<size && s[L]==s[R]; L--,R++); 
            // if(s[L]!=s[R] || L==0 || R==size-1) {
            L++;R--;
            palindromeLen = R-L+1;
            if(palindromeLen>maxPalindromeLen) {
                maxPalindromeLen = palindromeLen;
                pos = L;
                n = maxPalindromeLen;
            }
        }
        return s.substr(pos,maxPalindromeLen);
        }
    };
    int main() {
        Solution s;
        cout<<s.longestPalindrome("bb")<<endl;
        cout<<s.longestPalindrome("abb")<<endl;
        return 0;
    }
