/*
  283. Move Zeroes - Easy

  Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

  Note that you must do this in-place without making a copy of the array.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                zeroCount++;
                i--;
            }
        }
        
        for (int i = 0; i < zeroCount; i++) {
            nums.push_back(0);
        }
    }
};