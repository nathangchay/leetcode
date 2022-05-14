/*
  740. Delete and Earn - Medium

  You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

    Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.

  Return the maximum number of points you can earn by applying the above operation some number of times.
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(10001, 0), dp(10001, 0);
        for (int num : nums) {
            count[num] += num;
        }
        
        dp[0] = count[0];
        dp[1] = max(count[0],  count[1]);
        
        for (int i = 2; i < 10001; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + count[i]);
        }
        
        return dp[10000];
    }
};