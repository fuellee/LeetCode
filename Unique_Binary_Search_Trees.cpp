/*
 * Unique_Binary_Search_Trees.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        long long result = 1;
        for(int i=1,m=2*n;i<=n-1;++i,--m)
            result *= m;
        for(int i=2;i<=n;++i)
            result /= i;
        return result;
    }
};
int main() {
    Solution s;
    for(auto i : {1,2,3,4,5})
        cout<<s.numTrees(i)<<endl;
    return 0;
}
