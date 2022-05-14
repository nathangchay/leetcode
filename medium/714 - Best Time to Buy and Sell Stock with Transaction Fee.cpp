/*
  714. Best Time to Buy and Sell Stock with Transaction Fee - Medium

  You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

  Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        if (n < 2) {
            return 0;
        }
        
        vector<int> buy(n, 0), sell(n, 0);
        
        buy[0] = 0;
        sell[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], sell[i - 1] + prices[i] - fee);
            sell[i] = max(sell[i - 1], buy[i - 1] - prices[i]);
        }
        
        return buy[n - 1];
    }
};