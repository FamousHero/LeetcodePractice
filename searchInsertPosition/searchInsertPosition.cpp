#include <vector>

//Simple Binary Search alg for O(log(n)) runtime.
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        while(left <= right)
        {
            mid = left + (right-left)/2;
            int currentVal = nums[mid];
            if(currentVal == target)
                return mid;
            if(currentVal < target)
                left = mid+1;
            else if(currentVal > target)
                right = mid-1;
        }
        return nums[mid] > target? mid: mid+1;
    }
};