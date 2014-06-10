/*
 * Decode_Ways.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1 <= c1 c2 <= 26
    static inline bool valid(const char c1, const char c2) {
        if(c1=='1') return true;
        else if(c1=='2') return (c2<='6');
        else return false;
    }
    int numDecodings(string s) {
        int n = s.size();
        if(n<1) return 0;
        vector<int> DP(n+1);
        // 首位特殊处理
        if(s[0]!='0') 
            DP[0]=DP[1]=1;
        else return 0;
        // 从第二位开始DP
        for(int i=1;i<n;i++) {
            if(s[i]!='0')
                DP[i+1] += DP[i];
            if(valid(s[i-1],s[i]))
                DP[i+1] += DP[i-1];
        }
        return DP[n];
    }
};
int main() {
    Solution s; 
    cout<<(s.numDecodings("0")==0)<<endl;
    cout<<(s.numDecodings("1")==1)<<endl;
    cout<<(s.numDecodings("11")==2)<<endl;
    cout<<(s.numDecodings("10")==1)<<endl;
    return 0;
}
