class Solution {
public:
    void maxProfitRE(vector<int>& prices, int &i, int &buy, int &sell, int &pl) {
        // base case
        if(i >= prices.size()) {
            return;
        }


        // let's solve 1 case
        if(prices[i] > sell) {
            sell = prices[i];
            pl = max(pl, sell-buy);
        }
        else if(prices[i] < buy) {
            buy = sell = prices[i];
            pl = max(pl, sell-buy);
        }


        // rr
        i++;
        maxProfitRE(prices, i, buy, sell, pl);
    }

    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int sell = INT_MAX;
        int pl = 0;
        int i = 0;
        maxProfitRE(prices, i, buy, sell, pl);

        return pl;
    }
};