class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        compliments = {}
        for i,n in enumerate(nums):
            base = nums[i]
            if(base in compliments):
                return [compliments[base], i]
            compliments[target - base] = i
        return