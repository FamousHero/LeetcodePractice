from typing import List
#you only do var = var = value in python since dec and def happen at same time
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total = start = tank = 0
        for i in range(len(gas)):
            DIFF = gas[i] - cost[i]
            total += DIFF
            tank += DIFF
            if(tank < 0):
                tank = 0
                start = i+1
        if(total >= 0):
            return start
        return -1