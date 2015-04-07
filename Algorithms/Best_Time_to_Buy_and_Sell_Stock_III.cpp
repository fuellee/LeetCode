/*
 * Best_Time_to_Buy_and_Sell_Stock_III.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include "print.hpp"
#include <climits>
using namespace std;
#define DEBUG
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<int> forward(n),backward(n+1);
        int minPri=prices[0];
        // scan forward, maxProfit do at most 1 transaction trade 
        for (int i=1; i<n; ++i) {
            forward[i] = max(forward[i-1],prices[i]-minPri);
            minPri = min(minPri,prices[i]);
        }
        // scan backward, maxProfit do at most 1 transaction trade 
        int maxPri=prices[n-1];
        for (int i=n-2; i>=0; --i) {
            backward[i] = max(backward[i+1],maxPri-prices[i]);
            maxPri = max(maxPri,prices[i]);
        }
        int maxProfit=0;
        for (int i=0; i<n; ++i)
            maxProfit = max(maxProfit, forward[i]+backward[i+1]);
        #ifdef DEBUG
        cout<<endl;
        cout<<forward<<endl;
        cout<<backward<<endl;
        #endif
        return maxProfit;
    }
};
int main() {
    Solution s;
    // vector<int> prices1 {1,2};
    // cout<<s.maxProfit(prices1)<<endl;
    // vector<int> prices2 {2,1,2,0,1};
    // cout<<s.maxProfit(prices2)<<endl;
    vector<int> prices3 {3,2,6,5,0,3};
    cout<<s.maxProfit(prices3)<<endl;
    return 0;
}
