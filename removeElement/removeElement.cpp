#include <vector>
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int current_index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[current_index] = nums[i];
                ++current_index;
            }
        }
        return current_index;
    }
};

//Previous attempt: Doesn't work. Too many bound checks. Answer above
//works bc its like duplicating to a new array when u think about it

/*
class Solution {
public:
    Iterate through the array, find nums[n] == val => remove in-place
    nums does not have to be ordered
    return nums.size() after removals
    
    BEGIN
        int size = 0;
        int end = findElementNotVal(nums.size()-1);
        for(int i = 0; i < end; i++){
            if(nums[i] == val){
                swap(nums[i], nums[end]);
                end = findElementNotVal(end);
            }
            else{ //this element is not val, so it counts in list size
                ++size;
            }
        }
        return size;
    END
    
    BEGIN
        FindElementNotVal(vector<int>& nums, int currentEnd, int val)
            end = currentEnd;
            while(nums[end] == val){
                --end;
            }
            return end;
    END:
    int findEndIndex(vector<int>& nums, int current_end_index, int val){          
        while(current_end_index >= 0 && nums[current_end_index] == val){
            --current_end_index;
        }
        return current_end_index;
    }
    int removeElement(vector<int>& nums, int val) {
        int size = 0;
        int end_index = findEndIndex(nums, nums.size()-1, val);
         if(nums.empty() || end_index <= 0){
            return 0;
        }
        for(int i = 0; i <= end_index; i++){
            if(nums[i] == val){
                swap(nums[i], nums[end_index]);
                end_index = findEndIndex(nums, end_index, val);
            }
            ++size;
        }
        return size;
    }
};
*/