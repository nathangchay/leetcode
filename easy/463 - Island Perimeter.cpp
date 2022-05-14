/*
  463. Island Perimeter - Easy

  You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

  Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected
  land cells).

  The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular,
  width and height don't exceed 100. Determine the perimeter of the island.
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    if (i-1 < 0 || grid[i-1][j] == 0) {
                        perimeter++;
                    }
                
                    if (j+1 >= grid[i].size() || grid[i][j+1] == 0) {
                        perimeter++;
                    }

                    if (i+1 >= grid.size() || grid[i+1][j] == 0) {
                        perimeter++;
                    }

                    if (j-1 < 0 || grid[i][j-1] == 0) {
                        perimeter++;
                    }
                }
            }
        }
        
        return perimeter;
    }
};