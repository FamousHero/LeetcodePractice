#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int trueIndex = 0;
        if(nums.size() == 0)
            return 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == nums[trueIndex])
                continue;
            else
            {
                nums[++trueIndex] = nums[i];
            }
        }
        return trueIndex+1;//index starts at 0 so add 1 to ans
    }
};
