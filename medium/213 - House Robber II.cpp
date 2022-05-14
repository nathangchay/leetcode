/*
  213. House Robber II - Medium

  You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
  That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two
  adjacent houses were broken into on the same night.

  Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpF(n, 0), dpL(n, 0);
        
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }
        
        dpF[0] = nums[0];
        dpF[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n - 1; i++) {
            dpF[i] = max(nums[i] + dpF[i - 2], dpF[i - 1]);
        }
        
        dpL[1] = nums[1];
        dpL[2] = max(nums[1], nums[2]);
        
        for (int i = 3; i < n; i++) {
            dpL[i] = max(nums[i] + dpL[i - 2], dpL[i - 1]);
        }
        
        return max(dpF[n - 2], dpL[n - 1]);
    }
};