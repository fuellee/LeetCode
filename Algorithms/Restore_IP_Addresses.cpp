/*
 * Restore_IP_Addresses.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

// 人肉把有限深度递归转化成嵌套循环 
#include <iostream>
#include "print.hpp"
using namespace std;
class Solution {
    inline bool valid(const string &s) {
        if(s=="0") return true; 
        else if(/* s.empty() || */s[0]=='0') return false;
        else {
            int v = stoi(s);
            return v>=0 && v<=255;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        if(len>12) return {};
        vector<string> res;  
        for(int i=1; i<min(len-2,4);i++) {
            string &&p1 = s.substr(0,i);
            if(valid(p1))
                for(int j=i+1; j<min(len-1,i+4);j++) {
                    string &&p2 = s.substr(i,j-i);
                    if(valid(p2)) 
                        for(int k=j+1; k<min(len,j+4);k++) {
                            string &&p3 = s.substr(j,k-j);
                            string &&p4 = s.substr(k,len-k);
                            if(valid(p3) && valid(p4))
                                res.push_back(p1+'.'+p2+'.'+p3+'.'+p4);
                        }
                }
        }
        return res;
    }
};
int main() {
    Solution s;
    // cout<<s.restoreIpAddresses("25525511135")<<endl;
    cout<<s.restoreIpAddresses("0000")<<endl;
    return 0;
}
