#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>

/** Intuitive Solulion (TLE) - 
    For each cell, flip it if its 0 & check 
    how big the island is

    Time Complexity - O((m*n)^2)
    for each element, check all elements that connect to it.
    possible to visit each element for every element thus (m*n)^2 or n^4


 */
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxIsland = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0){
                    grid[i][j] = 1;
                    maxIsland = max(maxIsland, calculateIsland(grid, i, j));
                    grid[i][j] = 0;
                }
                maxIsland = max(maxIsland, calculateIsland(grid, i, j));
            }
        }
        return maxIsland;
    }

    int calculateIsland(vector<vector<int>>& grid, int i, int j){
        std::queue<std::pair<int,int>> toCheck;
        std:set<std::pair<int,int>> visited;
        toCheck.push(std::make_pair(i,j));
        int size = 0;
        //std::cout << "starting coords: (" << i << ", " << j << ")\n---------------------\n";
        while(!toCheck.empty()){
            std::pair<int, int> coords = toCheck.front(); toCheck.pop();
            int curr_x = coords.first;
            int curr_y = coords.second;
            //std::cout << "x: " << curr_x << ", y: " << curr_y << std::endl;
            if(visited.find(coords) != visited.end() || grid[curr_x][curr_y] == 0){
                continue;
            }
            //std::cout << "adding to size\n";
            ++size;
            if(curr_x > 0){
                toCheck.push(std::make_pair(curr_x - 1, curr_y));
                //std::cout << "x - 1, y \n";
            }
            if(curr_x < grid.size() - 1){
                toCheck.push(std::make_pair(curr_x + 1, curr_y));
                //std::cout << "x + 1, y \n";
            }
            if(curr_y < grid.size() - 1){
                toCheck.push(std::make_pair(curr_x, curr_y + 1));
                //std::cout << "x, y + 1 \n";
            }
            if(curr_y > 0){
                toCheck.push(std::make_pair(curr_x, curr_y - 1));
                //std::cout << "x, y - 1 \n";
            }
            visited.insert(coords);


        }
        return size;
    }
};

/** Accepted Solution
    Only visit each cell once. After visit, mark it with island id.
    This reduces Time Complexity to O(m*n) since once visited, it won't
    check every cell connected to it again.

    Reference: https://www.youtube.com/watch?v=8XEIO3hDHrQ&ab_channel=Techdose
 */

 #include <queue>
#include <set>
class Solution {
public:

    std::unordered_map<int,int> generateIslandSizes(vector<vector<int>>& grid, int n){
        int island_id = 2;
        std::unordered_map<int,int> island_sizes;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    int island_size = calculateIsland(grid, island_id, i, j);
                    island_sizes[island_id] = island_size;
                    ++island_id;
                }
            }
        }
        return island_sizes;
    }

    int generatePossibleIsland(vector<vector<int>>& grid, std::unordered_map<int,int>& island_sizes, int i, int j){
        std::unordered_set<int> islands;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int new_island = 1;
        for(int k=0; k < 4; ++k)
        {
            int adj_x = i+dirs[k][0];
            int adj_y = j+dirs[k][1];
            if(isValidCoords(grid.size(), adj_x, adj_y))
            {
                islands.insert(grid[adj_x][adj_y]);
            }
        }
        for(auto island_id: islands)
        {
            new_island += island_sizes[island_id];
        }
        return new_island;
    }


    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int max_island = 0;
        std::unordered_map<int,int> island_sizes = generateIslandSizes(grid, n);
        if(island_sizes.size() == 1 && island_sizes[2] == n*n){
            return island_sizes[2];
        }

        
        for(int i=0; i < n; ++i)
        {
            for(int j=0; j < n; ++j)
            {
                if(grid[i][j] == 0)
                {
                    int new_island = generatePossibleIsland(grid, island_sizes, i, j);
                    max_island = max(max_island, new_island);
                }
            }
        }
        return max_island;
    }

    int calculateIsland(vector<vector<int>>& grid, int island_id, int i, int j){
        std::queue<std::pair<int,int>> toCheck;
        toCheck.push(std::make_pair(i,j));
        int size = 0;
        while(!toCheck.empty()){
            std::pair<int, int> coords = toCheck.front(); toCheck.pop();
            int curr_x = coords.first;
            int curr_y = coords.second;
            if(!isValidCoords(grid.size(), curr_x, curr_y) || grid[curr_x][curr_y] != 1){
                continue;
            }
            ++size;

            toCheck.push(std::make_pair(curr_x - 1, curr_y));
            toCheck.push(std::make_pair(curr_x + 1, curr_y));
            toCheck.push(std::make_pair(curr_x, curr_y + 1));
            toCheck.push(std::make_pair(curr_x, curr_y - 1));
            
            grid[curr_x][curr_y] = island_id;

        }
        return size;
    }

    bool isValidCoords(int n, int i, int j){
        return (i >= 0 && i < n && j>=0 && j<n);
    }
};