#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        std::vector<std::vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(seen.count(nums[i]) > 0)
                continue;
            std::unordered_map<int, int> value_index;
            std::unordered_set<int> dup;
            for(int j = i+1; j < nums.size(); ++j)
            {
                if(seen.count(nums[j]) > 0 ||dup.count(nums[j]) > 0)
                    continue;
                if(value_index.count(nums[j]) > 0)
                {
                    int k = value_index[nums[j]];
                    ans.push_back({nums[i], nums[j], nums[k]});
                    dup.insert(nums[j]);
                }
                else
                {
                    value_index[-nums[i]-nums[j]] = j;
                } 
                
            }
            seen.insert(nums[i]);
        }
        return ans;
    }
};