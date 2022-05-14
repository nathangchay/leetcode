/*
  122. Best Time to Buy and Sell Stock II - Medium

  You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

  On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on
  the same day.

  Find and return the maximum profit you can achieve.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int result = 0;
        int profit = 0;
        int minPrice = prices[0];
        
        if (n < 2) {
            return 0;
        }
        
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                profit = max(profit, prices[i] - minPrice);
            } else {
                minPrice = prices[i];
                result += profit;
                profit = 0;
            }
        }
        
        result += profit;
        
        return result;
    }
};