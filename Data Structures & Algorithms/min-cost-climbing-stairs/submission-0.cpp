class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // + 1 for "top"
        vector<int> dp(cost.size() + 1);
        //we can have the cost of getting to that step in the dp.
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i-1] + cost[i - 1], dp[i-2] + cost[i - 2]);
        }

        return dp[cost.size()];
    }
};
