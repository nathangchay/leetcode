/*
  152. Maximum Product Subarray - Medium

  Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

  The test cases are generated so that the answer will fit in a 32-bit integer.

  A subarray is a contiguous subsequence of the array.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int totMax = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(curMax, curMin);
            }
            
            curMax = max(nums[i], curMax * nums[i]);
            curMin = min(nums[i], curMin * nums[i]);
            
            totMax = max(totMax, curMax);
        }
        
        return totMax;
    }
};