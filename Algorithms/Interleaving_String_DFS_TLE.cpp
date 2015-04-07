/*
 * Interleaving_String.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <functional>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        function<bool(size_t,size_t,size_t)> search = 
            [& search,s1,s2,s3]
            (size_t i1,size_t i2,size_t i3) {
            if(i1==s1.size() && i2==s2.size()) return true;
            else if(i1==s1.size())
                return s2.compare(i2,s2.size()-i2,s3,i3,s3.size()-i3)==0;
            else if(i2==s2.size())
                return s1.compare(i1,s1.size()-i1,s3,i3,s3.size()-i3)==0;
            else {
                bool res=false;
                if(s1[i1]==s3[i3]) res |= search(i1+1,i2,i3+1);
                if(s2[i2]==s3[i3]) res |= search(i1,i2+1,i3+1);
                return res;
            }
        };
        return search(0,0,0);
    }

};
int main() {
    Solution s;
    string s1 = "aabcc", s2 = "dbbca";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";
    cout<<s.isInterleave(s1,s2,s3)<<endl;
    cout<<s.isInterleave(s1,s2,s4)<<endl;
    cout<<s.isInterleave("accccaabbccabccabbcaabaabccccbbcabcabaccccabcaccbbccaaaccab", "cbaccbcaaaaacabbbbaaaccbabbcbcbbbbbbabcbbabaababaa", "cbaccbcaaccaaccaabbcacacaabbbbbaccaaacbcbabbbcbccaabbaabbbbcccbbcabbbcbcababbcaabaabcabacaccabcaccbbccaaaccab"
                         )<<endl;
    return 0;
}
