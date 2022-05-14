/*
  121. Best Time to Buy and Sell Stock - Easy

  You are given an array prices where prices[i] is the price of a given stock on the ith day.

  You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

  Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int result = 0;
        int minPrice = prices[0];
        
        if (n < 2) {
            return 0;
        }
        
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                result = max(result, prices[i] - minPrice);
            } else {
                minPrice = min(minPrice, prices[i]);
            }
        }
        
        return result;
    }
};