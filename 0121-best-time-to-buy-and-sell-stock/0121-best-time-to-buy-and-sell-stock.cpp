class Solution {
public:
    void maxProfitRE(vector<int>& prices, int i, int &minPrice, int &maxProfit) {
        // Base case
        if(i >= prices.size()) {
            return;
        }

        // Let's solve 1 case
        if(minPrice  > prices[i]) {
            minPrice = prices[i];
        }
        maxProfit = max(maxProfit, prices[i]-minPrice);
        
        // RE
        maxProfitRE(prices, i+1, minPrice, maxProfit);
    }

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;

        maxProfitRE(prices, 0, minPrice, maxProfit);

        return maxProfit;
    }
};