/*
 * Permutation_Sequence.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int circle = 1;
        for(int i=2; i<=n; i++) circle*=i;
        k -= 1; k %= circle;

        string nums(n,'0');
        for(int i=1; i<=n; i++) nums[i-1]+=i;

        string seq;

        while(n){
            circle /= n;
            int idx = k/circle;
            k %= circle;
            seq.push_back(nums[idx]);
            nums.erase(nums.begin()+nums.find(nums[idx]));
            n--;
        }

        return seq;
    }
};

int main() {
    Solution s;   
    for (int k = 1; k<6+1; ++k) {
       cout<<s.getPermutation(3,k)<<endl;
    }
    return 0;
}
