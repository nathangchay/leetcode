/*
  78. Subsets - Medium

  Given an integer array nums of unique elements, return all possible subsets (the power set).

  The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int m;
        vector<vector<int>> result;
        vector<int> newSubset;
        
        result.push_back({});
        
        for (int i = 0; i < n; i++) {
            m = result.size();
            for (int j = 0; j < m; j++) {
                newSubset = result[j];
                newSubset.push_back(nums[i]);
                result.push_back(newSubset);
            }
        }
        
        return result;
    }
};