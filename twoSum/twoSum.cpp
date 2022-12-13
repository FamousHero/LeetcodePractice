/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

class Solution {
public:
    /**
     * Solution 1: Brute force O(n^2)
     *  foreach(number1 in array)
     *  {
     *      foreach(number2 in array)
     *      { 
     *          if(number1 + number2 == target)
     *              return index of number1 and number2
     *      }
     *  }
     * 
     * This works but requires traversing the list twice which is inefficient.
     * Instead we should keep track of the compliment to each number in the array and the current index.
     * When we encounter a number that is a compliment, we can return the current index and the one previously saved.
     * The runtime complexity  is O(n) with an extra O(n) space complexity since
     * we need to store all the numbers we've iterated through. If we store these in 
     * a hashmap, insertion and searching will be O(1) making the Big-O O(n + 1) ~ O(n).
     * 
     * 
     *  
    **/
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> compliment;
        for(int i = 0; i < nums.size(); ++i)
        {
            int base = nums[i];
            if(compliment.count(base)) //Only one solution so return when found
            {
                return std::vector<int> {i, compliment[base]};
            }
            compliment[target-base] = i; //store the bases compliment to check against 
        }
        return std::vector<int> {0};
    }
};