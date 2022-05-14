/*
  34. Find First and Last Position of Element in Sorted Array - Medium

  Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

  If target is not found in the array, return [-1, -1].

  You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> output;
        output.push_back(-1);
        output.push_back(-1);
        
        if (nums.size() == 0) {
            return output;
        }
        
        int lo = 0;
        int hi = nums.size() - 1;
        
        while (lo <= hi) {
            if (nums[lo] == target) {
                output[0] = lo;
                
                while (lo < nums.size() && nums[lo] == target) {
                    lo++;
                }
                
                output[1] = lo - 1;
                
                break;
            }
            
            if (nums[hi] == target) {
                output[1] = hi;
                
                while (hi >= 0 && nums[hi] == target) {
                    hi--;
                }
                
                output[0] = hi + 1;
                
                break;
            }
            
            lo++;
            hi--;
        }
        
        return output;
    }
};