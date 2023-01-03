from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if(grid[i][j] == '1'):
                    self._dfs(i, j, grid)
                    islands += 1
        return islands
    
    def _dfs(self, i: int, j: int, grid: List[List[str]]) -> None:
        if(i < 0 or i >= len(grid) or 
           j < 0 or j >= len(grid[0]) or
           grid[i][j] == '0'):
            return
        grid[i][j] = '0'
        self._dfs(i+1, j, grid)
        self._dfs(i-1, j, grid)        
        self._dfs(i, j+1, grid)        
        self._dfs(i, j-1, grid)      