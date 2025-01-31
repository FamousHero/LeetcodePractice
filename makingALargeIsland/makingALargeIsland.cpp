#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>

/** Intuitive Solulion (TLE) - 
    For each cell, flip it if its 0 & check 
    how big the island is

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