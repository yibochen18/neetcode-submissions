class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice = 0, minPrice = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            else {
                maxPrice = max(maxPrice, prices[i] - minPrice);
            }
        }

        return maxPrice;
    }
};
