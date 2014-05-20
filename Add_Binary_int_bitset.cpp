/*
 * Add_Binary.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <bitset>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int sum = stoi(a,nullptr,2)+stoi(b,nullptr,2);
        string res = bitset<sizeof(sum)*8>(sum).to_string();
        return sum? res.substr(res.find('1')): "0";
    }
}; int main() { Solution s; 
    cout<<s.addBinary("11","1");
       
    return 0;
}
