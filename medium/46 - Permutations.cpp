/*
  46. Permutations - Medium

  Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/

class Solution {
public:
    void recurse(vector<vector<int>>& result, vector<int> cur, vector<int> remaining) {
        int n = remaining.size();
        vector<int> cur_temp;
        vector<int> remaining_temp;
        
        if (n == 1) {
            cur.push_back(remaining[0]);
            result.push_back(cur);
        } else {
            for (int i = 0; i < n; i++) {
                cur_temp = cur;
                remaining_temp = remaining;
                
                cur_temp.push_back(remaining[i]);
                remaining_temp.erase(remaining_temp.begin() + i);
                
                recurse(result, cur_temp, remaining_temp);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> cur;
        
        recurse(result, cur, nums);
        
        return result;
    }
};