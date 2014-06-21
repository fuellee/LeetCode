/*
 * Two_Sum.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <FooBee/out>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int L=0,R=numbers.size()-1;

        // index sort
        vector<int> I(R+1);
        for(int i=0;i<=R;i++) I[i]=i;
        sort(I.begin(),I.end(),[&numbers](const int &l,const int &r){return numbers[l]<numbers[r];});
        // cout<<numbers<<endl;
        // cout<<I<<endl;
        // for(int i=0; i<=R; i++)
        //     cout<<numbers[I[i]]<<" ";
        // cout<<endl;

        while(L<R) {
            int sum2 = numbers[I[L]]+numbers[I[R]];
            if(sum2==target)
                return {min(I[L],I[R])+1,max(I[L],I[R])+1};
            else if(sum2>target) R--;
            else L++;
        }
        return {};
    }
};
int main() {
    Solution s;
    vector<int> numbers={2, 7, 11, 15,1};
    cout<<s.twoSum(numbers,9)<<endl;
    vector<int> numbers1={150,24,79,50,88,345,3};
    cout<<s.twoSum(numbers1,200)<<endl;
    return 0;
}
