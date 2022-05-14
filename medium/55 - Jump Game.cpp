/*
  55. Jump Game - Medium

  You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that
  position.

  Return true if you can reach the last index, or false otherwise.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool res = false;
        vector<bool> dp(n, false);
        
        if (n == 1) {
            return true;
        }
        
        dp[n - 1] = true;
        
        for (int i = n - 1; i >= 0; i--) {
            res = false;
            
            for (int j = 1; j <= nums[i]; j++) { 
                if (i + j >= n - 1 || dp[i + j] == true) {
                    res = true;
                    break;
                }
            }
            
            dp[i] = res;
        }
        
        return dp[0];
    }
};