class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0) return 0;
        int Min = prices[0], Max=0;
        for(auto p:prices){
            Min=min(Min,p);
            Max=max(Max,p-Min);
        }
        return Max;
    }
};
