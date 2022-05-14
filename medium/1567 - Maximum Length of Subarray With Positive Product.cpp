/*
  1567. Maximum Length of Subarray With Positive Product - Medium

  Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

  A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

  Return the maximum length of a subarray with positive product.
*/

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int firstNeg = -1;
        int zeroPos = -1;
        int sum = 0;
        int totMax = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                sum++;
                
                if (firstNeg == -1) {
                    firstNeg = i;
                }
            }
            
            if (nums[i] == 0) {
                sum = 0;
                firstNeg = -1;
                zeroPos = i;
            } else {
                if (sum % 2 == 0) {
                    totMax = max(i - zeroPos, totMax);
                } else {
                    totMax = max(i - firstNeg, totMax);
                }
            }
        }
        
        return totMax;
    }
};