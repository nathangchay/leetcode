/*
  48. Rotate Image - Medium

  You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

  You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                matrix[i].push_back(matrix[j][i]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            matrix[i].erase(matrix[i].begin(), matrix[i].begin() + n);
        }
    }
};