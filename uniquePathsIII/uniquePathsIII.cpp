#include <vector>

/** DFS problem/Backtracking
 *  Pretty straight forwards brute force solution. Thought of 
 *  possibility of DP but it was just backtracking. Can't 
 *  store values because ur not really storing any value besides
 *  the count. O(3^n) since every cell has 3 options (after the 1st)
 *  on which direction to go and we have to visit every cell.
 *  3 * 3 * 3 *.... => 3^n
*/
class Solution {
public:
    int uniquePathsIII(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cells = 0,
        startX = 0, startY = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] != -1)
                {
                    ++cells;
                    if(grid[i][j] == 1)
                    {
                        startY = i;
                        startX = j;
                    }
                }
            }
        }
        grid[startY][startX] = 0;
        return dfs(startY, startX, 0, grid, cells);
    }
    
    int dfs(int currY, int currX, int visited, std::vector<std::vector<int>>& grid, int cells)
    {
        
        if(currX < 0 || currX > grid[0].size()-1 || currY < 0 || currY > grid.size() -1)
            return 0;
        if(grid[currY][currX] == 2)
        {
            if(visited == cells-1)
                return 1;
            return 0;
        }
        else if(grid[currY][currX] == 0)
        {
            ++visited;
            grid[currY][currX] = -1;
            int left, right, top, down;
            left = currX < 0? 0: dfs(currY, currX-1, visited, grid, cells);
            right = currX > grid[0].size()-1 ? 0: dfs(currY, currX+1, visited, grid, cells);
            top = currY < 0? 0: dfs(currY-1, currX, visited, grid, cells);
            down = currY > grid.size()-1? 0: dfs(currY+1, currX,  visited, grid, cells);
            --visited;
            grid[currY][currX] = 0;
            return left + right + top + down;
        }
        return 0;
    }
};