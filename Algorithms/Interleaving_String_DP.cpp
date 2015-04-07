/*
 * Interleaving_String_DP.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <FooBee/out>
using namespace std;
class Solution {
public:
// DP[i1][i2] = (DP[i1-1][i2] && s1[i1]==s3[i3]) || (DP[i1][i2-1] && s2[i2]==s3[i3])
    bool isInterleave(string s1, string s2, string s3) {
        const int n1=s1.size(), n2=s2.size(), n3=s3.size();
        if(n1+n2!=n3) return false;

        vector<bool> DP(n2+1,true);
        for(int i2=0; i2<n2; i2++) // DP[0][i2] (init first row)
            DP[i2+1] = DP[i2]&&(s2[i2]==s3[i2]); // check s3[:i2+1]==s2[:i2+1]

        for(int i1=0; i1<n1; i1++) {
            DP[0] = DP[0] && s1[i1]==s3[i1]; // DP[i1][0]: check s3[:i1+1]==s1[:i1+1]
            for(int i2=0; i2<n2; i2++)
                DP[i2+1] = (DP[i2+1] && s1[i1]==s3[i1+i2+1]) || (DP[i2] && s2[i2]==s3[i1+i2+1]);
        }
        return DP[n2];
    }
};

int main() {
    Solution s;
    string s1 = "aabcc", s2 = "dbbca";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";
    cout<<s.isInterleave(s1,s2,s3)<<endl; // true
    cout<<s.isInterleave(s1,s2,s4)<<endl; // false
    cout<<s.isInterleave("", "ab","4")<<endl; // false
    cout<<s.isInterleave("accccaabbccabccabbcaabaabccccbbcabcabaccccabcaccbbccaaaccab", "cbaccbcaaaaacabbbbaaaccbabbcbcbbbbbbabcbbabaababaa", "cbaccbcaaccaaccaabbcacacaabbbbbaccaaacbcbabbbcbccaabbaabbbbcccbbcabbbcbcababbcaabaabcabacaccabcaccbbccaaaccab")<<endl; // true
    cout<<s.isInterleave("aacaac", "aacaaeaac", "aacaaeaaeaacaac")<<endl; // false
    return 0;
}
