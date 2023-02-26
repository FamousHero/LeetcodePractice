#include <vector>
#include <unordered_set>
#include <queue>

//Simple BFS, could use DFS but looking at runtime dist, not much of a difference,
//biggest reason would be memory dist. Can use vector instead of unordered_set
//but need DFS to remove queue and change 'toVisit' to 'visited'
class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        std::unordered_set<int> toVisit;
        int provinces = 0;
        for(int i = 0; i < isConnected.size(); ++i){
            toVisit.insert(i);
        }
        while(!toVisit.empty()){
            std::queue<int> connected;
            int temp = *toVisit.begin();
            connected.push(temp);
            while(!connected.empty()){
                int start = connected.front(); connected.pop();
                toVisit.erase(start);
                for(int i = 0; i < isConnected[start].size(); ++i){
                    if(isConnected[start][i] == 1 && toVisit.count(i) > 0){
                        connected.push(i);
                        toVisit.erase(i);
                    }
                }
                
            }
            ++provinces;
            
        }
        return provinces;
    }
};

/**
 * DFS SOLUTION
 * class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<int> visited(isConnected.size(), 0);
        int toVisit = isConnected.size();
        int city = 0;
        while(toVisit){
            for(int i = 0; i < visited.size(); ++i){
                if(!visited[i]){
                    DFS(i, isConnected, visited, toVisit);
                    ++count;
                }
            }
        }
        return count;
    }
    
    void DFS(int city, std::vector<std::vector<int>>& isConnected, std::vector<int>& visited, int& toVisit){
        visited[city] = 1;
        --toVisit;
        for(int i = 0; i < isConnected[city].size(); ++i){
            if(isConnected[city][i] == 1 && !visited[i]){
                DFS(i, isConnected, visited, toVisit);
            }
        }
    }
};
*/