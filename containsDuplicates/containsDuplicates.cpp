#include <vector>
#include <set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> count;
        for(int i=0; i < nums.size(); ++i)
        {
            if(count.count(nums[i]) > 0)
                return true;
            count.insert(nums[i]);
        }
        return false;
    }
};