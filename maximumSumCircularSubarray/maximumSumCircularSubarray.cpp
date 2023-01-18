#include <vector>
#include <algorithm>
class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int total = 0, prefixMax = INT_MIN, currMax = INT_MIN,
            minSum = INT_MAX, currMin = INT_MAX;
        for(int i = 0; i < nums.size(); ++i)
        {
            total += nums[i];
            currMax = std::max(0, currMax) + nums[i]; //if the currMax(sum) goes negative restart from this index
            prefixMax = std::max(currMax, prefixMax); //If the current subarray we are in is bigger than any before, store it
            currMin = std::min(0, currMin) + nums[i]; //find largest min subarray before + nums[i] > 0
            minSum = std::min(minSum, currMin); //Store the largest min subarray in case looping around makes a bigger sum
        }
        //if the whole array is negative, return the largest number we found (prefixMax) else check if removing the negative subarray would make it bigger
        return minSum == total? prefixMax: std::max(prefixMax, total - minSum);
    }
};