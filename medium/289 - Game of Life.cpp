/*
  289. Game of Life - Medium

  According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

  The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its
  eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population.
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

  The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current
  state of the m x n grid board, return the next state.
*/

class Solution {
public:
    int getNeighborsCount(int m, int n, vector<vector<int>>& board) {
        int sum = 0;
        
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (
                    m + i >= 0 && m + i < board.size() &&
                    n + j >= 0 && n + j < board[0].size() &&
                    board[m + i][n + j] == 1
                ) {
                    /*
                    cout << "m + i = " << m + i << " & board.size() = " << board.size() << endl;
                    cout << "n + j = " << n + j << " & board[0].size() = " << board[0].size() << endl;
                    cout << "board[m + i][n + j] = " << board[m + i][n + j] << endl;
                    */
                    sum++;
                }
            }
        }
        
        if (board[m][n] == 1) {
            sum--;
        }
        
        return sum;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> result = board;
        int neighbors;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                neighbors = getNeighborsCount(i, j, board);
                cout << "board[" << i << "][" << j << "] neighbors: " << neighbors << endl;
                
                if (board[i][j] == 1) {               
                    if (neighbors < 2 || neighbors > 3) {
                        result[i][j] = 0;
                    } else {
                        result[i][j] = 1;
                    }
                } else {
                    if (neighbors == 3) {
                        result[i][j] = 1;
                    }
                }
            }
        }
        
        board = result;
    }
};