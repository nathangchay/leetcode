/*
  53. Maximum Subarray - Easy

  Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

  A subarray is a contiguous part of an array.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        int curMax;
        
        dp[0] = nums[0];
        curMax = dp[0];
        
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            curMax = max(curMax, dp[i]);
        }
        
        return curMax;
    }
};