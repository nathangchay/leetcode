/*
  413. Arithmetic Slices - Medium

  An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

    For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.

  Given an integer array nums, return the number of arithmetic subarrays of nums.

  A subarray is a contiguous subsequence of the array.
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int result = 0;
        int curSlices = 0;
        int curLength = 2;
        int curDiff = 0;
        
        if (n < 3) {
            return 0;
        }
        
        dp[0] = 0;
        dp[1] = 0;
        
        curDiff = nums[1] - nums[0];
        
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] != curDiff) {
                result += curSlices;
                curSlices = 0;
                curLength = 2;
                curDiff = nums[i] - nums[i - 1];
            } else {
                curLength++;
                
                if (curLength >= 3) {
                    if (curSlices == 0) {
                        curSlices = 1;
                    } else {
                        curSlices = (curLength - 2) * (curLength - 1) / 2;
                    }
                }
            }
        }
        
        result += curSlices;
        
        return result;
    }
};