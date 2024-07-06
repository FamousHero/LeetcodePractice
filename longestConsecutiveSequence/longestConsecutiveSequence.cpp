#include <set>
#include <algorithm>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> link;

        for(int i = 0; i < nums.size(); ++i)
        {
            link.insert(nums[i]);
        }

        int LCS = 0;
        int prev = INT_MIN;
        int currentLength = 1;
        for(auto n: link){
            if(prev == n-1)
                ++currentLength;
            else
                currentLength = 1;
            LCS = std::max(currentLength, LCS);
            prev = n;
        }

        return LCS;
    }
};
