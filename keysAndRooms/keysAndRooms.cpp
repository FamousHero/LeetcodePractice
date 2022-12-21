#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>

class Solution {
    /* When we have to visit one node and see where that node leads,
     * we need a queue. It's basically a BFS. Time Complexity O(n)
     * since its possible we check each rooms and the visited set ensures 
     * we only visit each room once. Space complexity O(n) since both visited and toVisited
     * can hold all elements.
     * OPTIMIZATION: instead of using stack, use a vector initialized with size of rooms and values 0.
     * this way you don't need to worry about possible reallocation with each insertion, just change value
     * to 1 after visited
     */
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        std::unordered_set<int> visited{0};
        std::queue<int> toVisit;
        for(int i=0; i < rooms[0].size(); ++i)
        {
            toVisit.push(rooms[0][i]);
        }
        while(!toVisit.empty())
        {
            int room = toVisit.front();
            for(int i = 0; i < rooms[room].size(); ++i)//i is each key in the room
            {
                if(visited.count(rooms[room][i]) == 0)//if we haven't visited that room
                {
                    toVisit.push(rooms[room][i]);
                }
            }
            toVisit.pop();
            visited.insert(room);
        }
        if(visited.size() == rooms.size())
            return true;
        return false;
        
        
        /* DFS solution (can also be recursive)
         * Question: which has more overhead, calls to stack.push and stack.pop or
         * recursive call to function which creates a stack frame each time
        std::stack<int> toVisit;
        toVisit.push(0);
        std::vector<int> visited(rooms.size(), 0);
        int visitCount = 1;
        while(!toVisit.empty())
        {
            if(visitCount == rooms.size())
                return true;
            int room = toVisit.top();
            toVisit.pop();
            visited[room] = 1;
            ++visitCount;
            for(auto it: rooms[room])//for each element in room[rooms] aka key
            {
                if(visited[it] == 0) //if we haven't visited it
                {
                    toVisit.push(it); //check what keys it has
                }
            }
        }
        return false;
        */

    }
};