/*
 * Best_Time_to_Buy_and_Sell_Stock_II.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        for(size_t i=1; i<prices.size(); ++i){
            int tmp = prices[i]-prices[i-1];
            if(tmp>0) res+=tmp;
        }
        return res;
    }
};
