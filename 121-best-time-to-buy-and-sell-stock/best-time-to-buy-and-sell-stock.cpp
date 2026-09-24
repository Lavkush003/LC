class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int bestbuy=INT_MAX;
        int profit=0;

        for(int i=0;i<prices.size();i++){
            bestbuy=min(bestbuy,prices[i]);
        
        
        
        profit=max(profit, prices[i]-bestbuy);
        }
        return profit;
        
    }
};