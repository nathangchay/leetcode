/*
  309. Best Time to Buy and Sell Stock with Cooldown - Medium

  You are given an array prices where prices[i] is the price of a given stock on the ith day.

  Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the
  following restrictions:

    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        if (n < 2) {
            return 0;
        }
        
        vector<int> buy(n, 0), sell(n, 0), rest(n, 0);
        
        buy[0] = 0;
        sell[0] = -prices[0];
        rest[0] = INT_MIN;
        
        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], rest[i - 1]);
            sell[i] = max(sell[i - 1], buy[i - 1] - prices[i]);
            rest[i] = sell[i - 1] + prices[i];
        }
        
        return max(buy[n - 1], rest[n - 1]);
    }
};