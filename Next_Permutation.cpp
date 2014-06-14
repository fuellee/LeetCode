/*
 * Next_Permutation.cpp
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
    void nextPermutation(vector<int> &num) {
        /* cout<<"num: "<<num<<endl; */
        const int n=num.size();
        int L=-1,R=-1; // init to impossible value
        // find the first order voilation `L`(from right most to left)
        for(int i=n-1; i>0; i--)
            if(num[i-1]<num[i]){
                L = i-1;
                break;
            }

        if(L==-1) // no order voilation <=> all in decendent order
            reverse(num.begin(),num.end());
        else {
            reverse(num.begin()+L+1, num.end());
            R = find_if(num.begin()+L+1, num.end(), 
                        [&num,&L](int e){return num[L]<e;}) - num.begin();
            swap(num[L],num[R]);
        }
    }
};
int main() {
    Solution s;    
    vector<int> num {5,1,1};
    // vector<int> num {1,2,3};
    cout<<num<<endl;
    for (int i = 0; i < 6; ++i){
        s.nextPermutation(num);
        cout<<num<<endl;
    }


    vector<int> num2 = {2,2,7,5,4,3,2,2,1};
    s.nextPermutation(num2);
    cout<<num2<<endl;
    // {2, 3, 1, 2, 2, 2, 4, 5, 7}
    return 0;
}
