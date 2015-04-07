/*
 * Divide_Two_Integers.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <cassert>
using namespace std;
class Solution {
public:
    // int divide(int dividend, int divisor) {
    int divide(long long dividend, long long  divisor) {
        bool sign = (dividend>0 && divisor<0) || (dividend<0 && divisor>0);
        long long dividend_ = abs(dividend);
        long long divisor_ = abs(divisor);
        cout<<"divisor_:"<<divisor_<<endl;
        cout<<dividend_<<"<"<<divisor_<<endl;
        cout<<"dividend_<divisor_: "<<(dividend_<divisor_)<<endl;
        if(dividend_<divisor_) return 0;
        int res=0;
        int upper_bound;
        while(dividend_>=0){
            for(upper_bound=1; divisor_<<upper_bound <= dividend_; ++upper_bound);
            res += 1<<(upper_bound-1);
            dividend_ -= divisor_<<(upper_bound-1);
        }
        res--;
        return sign? -res:res;
    }
};
int main() {
    Solution s;    
    // 诡异问题： 用 int时 abs结果是负的！
    cout<<s.divide(1010369383, 2147483648)<<endl;
    // cout<<s.divide(4,2)<<endl;
    // cout<<s.divide(2147483647,2)<<endl;
    // cout<<s.divide(21474838,2)<<endl;
    // cout<<s.divide(3,4)<<endl;
    // cout<<s.divide(4,3)<<endl;
    // cout<<s.divide(6,3)<<endl;
    // cout<<s.divide(7,3)<<endl;
    // cout<<s.divide(8,3)<<endl;
    // cout<<s.divide(9,3)<<endl;
    // cout<<s.divide(1,-1)<<endl;
    return 0;
}
