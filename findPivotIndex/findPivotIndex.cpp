#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<int> leftsum(size+1,0);
        std::vector<int> rightsum(size+1,0);
        for(int i = 0, j = size; i < size; ++i, --j)
        {
            leftsum[i+1] = nums[i] + leftsum[i];
            rightsum[j-1] = nums[j-1] + rightsum[j];
        }
        rightsum[0] = nums[0] + rightsum[1];

        for(int i = 0; i < leftsum.size()-1; ++i)
        {
            if(leftsum[i] == rightsum[i+1])
                return i;
        }
        return -1;
    }
};