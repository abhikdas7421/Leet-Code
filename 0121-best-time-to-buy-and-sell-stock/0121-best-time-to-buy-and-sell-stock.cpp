class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int profit = 0;
        int buying_price = prices[0];
        
        for(int i = 1; i < n; i++) {
            profit = max(profit, prices[i]-buying_price);
            buying_price = min(buying_price, prices[i]);
        }
        
        return profit;
    }
};