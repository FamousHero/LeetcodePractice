#include <vector>
 
class Solution {
public:
void reverse(std::vector<int>& nums,int start,int end)
    {
        while(start<=end)
        {
            std::swap(nums[start++],nums[end--]);
        }
    }
    
    void rotate(std::vector<int>& nums, int k) {
        k=k%nums.size();
		//reverse first partion
        reverse(nums,0,nums.size()-k-1);
		//rverse last partiton
        reverse(nums,nums.size()-k,nums.size()-1);
		//reverse the whole vector
        reverse(nums,0,nums.size()-1);
        
    }
};