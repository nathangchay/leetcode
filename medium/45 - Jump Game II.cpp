/*
  45. Jump Game II - Medium

  Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

  Each element in the array represents your maximum jump length at that position.

  Your goal is to reach the last index in the minimum number of jumps.

  You can assume that you can always reach the last index.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int localMin = INT_MAX - 1;
        vector<int> minStepsFrom(n, INT_MAX);
        
        if (n == 1) {
            return 0;
        }
        
        minStepsFrom[n - 1] = 0;
        
        for (int i = n - 2; i >= 0; i--) {
            localMin = INT_MAX - 1;
            
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j >= n) {
                    break;
                }
                
                localMin = min(minStepsFrom[i + j], localMin);
            }
            
            minStepsFrom[i] = localMin + 1;
        }
        
        return minStepsFrom[0];
    }
};