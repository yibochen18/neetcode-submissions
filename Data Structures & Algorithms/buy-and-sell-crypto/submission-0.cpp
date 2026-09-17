class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //treat index as sell price and look for maximum profit to the left
        int max_profit = 0;
        

        for (int i = 1; i < prices.size(); i++)
        {
            int profit;
            int sell_price = prices[i];
            for (int j = i - 1; j >= 0; j--)
            {
                profit = sell_price - prices[j];
                if (profit > max_profit)
                {
                    max_profit = profit;
                }
            }
        }

        return max_profit;
    }
};
