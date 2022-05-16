/*
  41. First Missing Positive - Hard

  Given an unsorted integer array nums, return the smallest missing positive integer.

  You must implement an algorithm that runs in O(n) time and uses constant extra space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int result = 1;
        int n = nums.size();
        unordered_map<int, bool> found;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == result) {
                result++;
                
                while (found[result]) {
                    result++;
                }
            }
            
            found[nums[i]] = true;
        }
        
        return result;
    }
};