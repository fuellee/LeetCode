/*
 * Add_Binary.cpp
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
    string addBinary(string a, string b) {
        size_t la=a.size(),lb=b.size();
        size_t lres=max(la,lb)+1;
        string res(lres,'0');
        int c=0;
        for(int i=lres-1,ia=la-1,ib=lb-1;i>=0;--i,--ia,--ib) {
            int x =c;
            if(ia>=0) x+=a[ia]-'0';
            if(ib>=0) x+=b[ib]-'0';
            c=x/2;
            x=x%2;
            res[i]=x+'0';
        }
        size_t pos = res.find('1');
        return pos==string::npos? "0": res.substr(pos);
    }
}; 

int main() { Solution s; 
    cout<<s.addBinary("11","1")<<endl;
    cout<<s.addBinary("0","0")<<endl;
       
    return 0;
}
