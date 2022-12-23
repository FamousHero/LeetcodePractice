#include <vector>
#include <set>
#include <utility>
class Solution {
    //DFS, when you encounter an island, check every piece of land connected to it, and
    //mark it as visited so you dont recount it. Need to check every direction since
    //in the case of an island
    /**
     * 000110
     * 001111
     * 000111
     * 
     * The first 1 in row 2 would count as its own island
    */
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        std::set<std::pair<int, int>> visited;
        int count = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                std::pair<int, int> coords = std::make_pair(i, j);
                if(visited.count(coords) == 0 && grid[i][j] == '1')
                {
                    ++count;
                    islandHelper(grid, i, j, visited);
                }
                else
                {
                    visited.insert(coords);
                }
            }
        }
        return count;
    }
    
    void islandHelper(std::vector<std::vector<char>>& grid, int i, int j, std::set<std::pair<int,int>>& visited)
    {
        if(i < 0 || i >= grid.size())
            return;
        if(j < 0 || j >= grid[0].size())
            return;
        std::pair<int,int> coords = std::make_pair(i, j);
        if(visited.count(coords) == 0 && grid[i][j] == '1')
        {
            visited.insert(coords);
            islandHelper(grid, i, j+1, visited);
            islandHelper(grid, i+1, j, visited);
            islandHelper(grid, i, j-1, visited);
            islandHelper(grid, i-1, j, visited);
        }
    }
};