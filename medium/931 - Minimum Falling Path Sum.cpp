/*
  931. Minimum Falling Path Sum - Medium

  Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

  A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the
  next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int add;
        int result;
        
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    add = min(dp[i - 1][j], dp[i - 1][j + 1]);
                } else if (j == n - 1) {
                    add = min(dp[i - 1][j - 1], dp[i - 1][j]);
                } else {
                    add = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]);
                }
                
                dp[i][j] = matrix[i][j] + add;
            }
        }
        
        result = dp[n - 1][0];
        for (int i = 1; i < n; i++) {
            result = min(result, dp[n - 1][i]);
        }
        
        return result;
    }
};