/*
  120. Triangle - Medium

  Given a triangle array, return the minimum path sum from top to bottom.

  For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1
  on the next row.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<vector<int>> dp(rows);
        int add;
        int result;
        
        dp[0].push_back(triangle[0][0]);
        
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (j == 0) {
                    add = dp[i - 1][j];
                } else if (j == dp[i - 1].size()) {
                    add = dp[i - 1][j - 1];
                } else {
                    add = min(dp[i - 1][j], dp[i - 1][j - 1]);
                }
                    
                dp[i].push_back(triangle[i][j] + add);
            }
        }
            
        result = dp[rows - 1][0];
        for (int i = 1; i < rows; i++) {
            result = min(result, dp[rows - 1][i]);
        }
            
        return result;
    }
};