/*
  1. Two Sum - Easy

  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

  You may assume that each input would have exactly one solution, and you may not use the same element twice.

  You can return the answer in any order.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int search;
        
        for (int i = 0; i < nums.size(); i++) {
            search = target - nums[i];
            
            if (hash.count(search) > 0) {
                return {i, hash[search]};
            } else {
                hash[nums[i]] = i;
            }
        }
        
        return {};
    }
};