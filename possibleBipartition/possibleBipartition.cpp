#include <vector>
/**
 * Relatively simple problem if u ready the instructions properly. For each person
 * make a list of the people they dislike. Everytime you place someone in a group,
 * place the people they dislike in the opposite group. This naturally becomes recursive
 * when you place the disliked person in the opposite group. They key here is to make 
 * the adjacency list bidirectional. This seems like unnecessary space but consider the 
 * case: 1 -> 5| 5 -> 10| 2 -> 10.
 * Without bidrectionality checking the alg will place 1 in grp 0, 5 in grp 1, 10 in grp 0.
 * When it gets to 2, it sees it as a disjoint graph meaning 2 goes in grp 0, but 10 is 
 * already in grp 0 meaning it will return false. 
 * (Result) grp 0: 1, 10, 2 - grp 1: 5
 * (Expected) grp 0: 1, 10 - grp 1: 5, 2
 * 
 * By making the graph bidirectional, we ensure every edge within a given graph, will
 * be visited through dfs.
 * 
 * 
*/
class Solution {
public:
    bool possibleBipartition(int n, std::vector<std::vector<int>>& dislikes) {
        std::vector<int> grouping(n+1, -1);
        std::vector<std::vector<int>> adjList(n+1);
        for(int i = 0; i < dislikes.size(); ++i)
        {
            adjList[dislikes[i][0]].push_back(dislikes[i][1]);
            adjList[dislikes[i][1]].push_back(dislikes[i][0]); //required
        }
        for(int i = 0; i <= n; ++i)
        {
            if(grouping[i] == -1)//if you havent assigned group 
            {
                if(!dfs(i, 0, adjList, grouping))
                    return false;
            }
        }
        return true;
    }
    
    bool dfs(int index, bool group, const std::vector<std::vector<int>>& adjList, std::vector<int>& grouping)
    {
        grouping[index] = group;
        for(int dislikers: adjList[index])
        {
            if(grouping[dislikers] == grouping[index])
                return false;
            if(grouping[dislikers] == -1)
                if(!dfs(dislikers, !group, adjList, grouping))
                    return false; //if this returns false we need to propogate up
        }
        return true;
    }
};