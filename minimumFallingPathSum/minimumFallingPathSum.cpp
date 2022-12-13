#include <algorithm>
#include <vector>
class Solution {
public:
/**
 * Classic DP problem
 * Initial idea was to double for loop -outer loop column and inner loop row
 * since you can start from any value in row 1
 * the issue is with a simple for loop you can only check the diagonals of your current
 * column, this means you miss possible branches where the current move may not be the lowest,
 * but will eventually lead to bigger payout 
 * EX:
 * 
 *  100 | -42 | -46 | -41
 * -----------------------
 *  31  |  97 |  10 | -10
 * -----------------------
 *  -58 | -51 |  82 |  89
 * -----------------------
 *   51 |  81 |  69 | -51
 * 
 *  The best path without just taking best choice at the time gives
 *  100 | -42 | -46 | -41
 * ---------- \ ----------
 *  31  |  97   10 | -10
 * ---------- / ----------
 *  -58 |  -51  |  82 |  89
 * ----- / ----------------
 *   51  |  81 |  69 | -51
 * 
 * Instead we should check all possible solutions which would yield
 * 
 *  100 | -42 | -46 | -41
 * ------------- | -------
 *  31  |  97 |  10 | -10
 * ---------- / ----------
 *  -58 |  -51 |  82 |  89
 * -----/ ----------------
 *   51 |  81 |  69 | -51
 * Time Complexity: O(n * m) since we we have to update the value of every element in 
 * the matrix.
*/
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        for(int i = 1; i < row; ++i) // row 0 is set so start on row 1
        {
            for(int j = 0; j < column; ++j)
            {
                if(j == 0)
                {
                    matrix[i][j] += std::min(matrix[i-1][j], matrix[i-1][j+1]);
                }
                else if(j == column-1)
                {
                    matrix[i][j] += std::min(matrix[i-1][j], matrix[i-1][j-1]);
                }
                else
                {
                    matrix[i][j] += std::min({matrix[i-1][j],matrix[i-1][j-1],matrix[i-1][j+1]});
                }
            }
        }
        int min = INT_MAX;
        for(int j = 0; j < column; ++j)
        {
            min = std::min(min, matrix[row-1][j]);
        }
        return min;
    }
    
};