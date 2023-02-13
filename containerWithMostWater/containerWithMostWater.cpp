#include <algorithm>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxArea = 0;
        int l = 0;
        int r = height.size()-1;
        while(l < r)
        {
            int maxHeight = std::min(height[l], height[r]);
            int currArea = maxHeight * (r-l);
            maxArea = std::max(maxArea, currArea);
            while(height[l] <= maxHeight && l < r)
            {
                ++l;
            }
            while(height[r] <= maxHeight && l < r)
            {
                --r;
            }
        }
        return maxArea;
    }
};