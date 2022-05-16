/*
  54. Spiral Matrix - Medium

  Given an m x n matrix, return all elements of the matrix in spiral order.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int depth = 0;
        
        while (depth < m / 2 + 1 && depth < n / 2 + 1) {
            for (int i = depth; i < n - depth; i++) {
                result.push_back(matrix[depth][i]);
                
                if (result.size() == n * m) {
                    return result;
                }
            }

            for (int i = depth + 1; i < m - depth; i++) {
                result.push_back(matrix[i][n - depth - 1]);
                
                if (result.size() == n * m) {
                    return result;
                }
            }

            for (int i = n - depth - 2; i >= depth; i--) {
                result.push_back(matrix[m - depth - 1][i]);
                
                if (result.size() == n * m) {
                    return result;
                }
            }

            for (int i = m - depth - 2; i >= depth + 1; i--) {
                result.push_back(matrix[i][depth]);
                
                if (result.size() == n * m) {
                    return result;
                }
            }
            
            depth++;
        }
        
        return result;
    }
};