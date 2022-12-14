from typing import List
class Solution:
    def rob(self, nums: List[int]) -> int:
        ans = nums[0]
        if(len(nums) == 1):
            return ans
        ans = max(ans, nums[1])
        nums[1] = ans
        for i in range(2, len(nums)):
            ans = max(nums[i-2]+nums[i], ans) 
            nums[i] = ans 
        return ans