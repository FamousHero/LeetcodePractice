#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        //Intuition: you know there exists a solution of sum(gas) - sum(cost) > 0
        //Possible solution is for each element in array, make a loop to check that its always > 0
        //This is O(n^2) since for each element, you have to traverse every other element.
        //Question: How can we make this O(n)? 
        //Solution: you start at index 0 and check gas[i] + inTank - cost[i]
        //if at any point this expression is < 0 we know there is no start point between i and our current start that 
        //can make it. Thus we set our new start point to the next element.
        //keep track of the running total since it can be (+) when we reach end but become (-) if we looped back.
        //And return start if its > 0. 
        
        int total(0), start(0), tank(0);
        for(int i = 0; i < gas.size(); ++i)
        {
            total += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0)
            {
                tank = 0;
                start = i+1;
            }
        }
        if(total >= 0)
            return start;
        return -1;
    }
};