class Solution
{
public:
  int func(vector<int> &prices, int buy, int ind, vector<vector<int>> &dp)
  {
    if (ind == prices.size())
      return 0;
    if (dp[ind][buy] != -1)
      return dp[ind][buy];
    int profit = 0;
    if (buy == 0)
    {
      int take = -prices[ind] + func(prices, 1, ind + 1, dp);
      int nottake = func(prices, 0, ind + 1, dp);
      profit = max(take, nottake);
    }
    else
    {
      int take = prices[ind] + func(prices, 0, ind + 1, dp);
      int nottake = func(prices, 1, ind + 1, dp);
      profit = max(take, nottake);
    }
    return dp[ind][buy] = profit;
  }
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    // vector<vector<int>> dp (n, vector<int> (2, -1));
    // return func(prices, 0, 0, dp);
    // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    // dp[n][0] = 0;
    // dp[n][1] = 0;
    // for (int ind = n - 1; ind >= 0; ind--) {
    //     for (int buy = 0; buy < 2; buy++) {
    //         int profit = 0;
    //         if (buy == 0) {
    //             int take = -prices[ind] + dp[ind + 1][1];
    //             int nottake = dp[ind + 1][0];
    //             profit = max(take, nottake);
    //         } else {
    //             int take = prices[ind] + dp[ind + 1][0];
    //             int nottake = dp[ind + 1][1];
    //             profit = max(take, nottake);
    //         }
    //         dp[ind][buy] = profit;
    //     }
    // }
    // return dp[0][0];
    vector<int> curr(2, 0);
    vector<int> next(2, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int buy = 0; buy < 2; buy++)
      {
        int profit = 0;
        if (buy == 0)
        {
          int take = -prices[ind] + next[1];
          int nottake = next[0];
          profit = max(take, nottake);
        }
        else
        {
          int take = prices[ind] + next[0];
          int nottake = next[1];
          profit = max(take, nottake);
        }
        curr[buy] = profit;
      }
      next = curr;
    }
    return next[0];
  }
};