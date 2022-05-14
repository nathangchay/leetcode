/*
  118. Pascal's Triangle - Easy

  Given an integer numRows, return the first numRows of Pascal's triangle.

  In Pascal's triangle, each number is the sum of the two numbers directly above it.
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        
        result[0] = {1};
        
        for (int i = 1; i < numRows; i++) {
            result[i].push_back(1);
            
            for (int j = 1; j < i; j++) {
                result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            
            result[i].push_back(1);
        }
        
        return result;
    }
};