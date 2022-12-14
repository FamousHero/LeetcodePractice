#include <vector>
#include <algorithm>
class Solution {
public:
    int rob(std::vector<int>& nums) {
        /**
         * need to know if its worth more to rob curr house and 2 houses before or skip and keep the money from 
         * prev house. If we have to keep track of previous answer then its a DP/recursive problem.
         * For every house check if its worth more to steal from this house and the max of the house we stole
         * from 2 away or if its worth more to skip the current house and keep the max amount we got from the
         * previous house. Once we know which is more, update the current houses max to that amount so we know 
         * what is the best option at this point.
         * Note: could store nums[i-1] and nums[i] in variables to avoid reading from list but since we 
         * constantly read from list it should already be in the cache so preformance is unaffected
        */ 

        int ans = 0;
        if(nums.size() == 1)
            return nums[0];
        ans = std::max(nums[0], nums[1]);
        nums[1] = ans; //updating the houses max amount at this point
        int prevHouses = nums[0]; 
        for(int i = 2; i < nums.size(); ++i)
        {
            ans = std::max(prevHouses+nums[i], ans); //get the current max as described above
            nums[i] = ans; //update to new max
            prevHouses = nums[i-1]; //prevHouses is the same as nums[i-2] when calculating ans
        }
        return ans;
    }
};