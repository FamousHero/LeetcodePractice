#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int target = nums.size();
        int currJump = nums[0];
        //true if no 0s
        for(int i = 0; i < target; ++i)
        {
            if(currJump < 0)
                return false;
            if(nums[i] > currJump)
            {
                currJump = nums[i];
            }
            --currJump;
        }
        return true;
    }
};