#include <vector>
#include <stack>
class Solution {
public:
    /* simple solution is for each day, check against remaining days - O(n^2)
     * Optimized solution: we need a way to keep track of the biggest days so that we only go through the array once. 
     * Note: for problems where you are looking for "the next ___ element" usually means use a stack to keep record.
     * Start from the end of the array and move backwards in order to know whats happening in the future. For each element,
     * put it in the stack since its possible to be the next greatest compared to past days. Also if the current day(index) is 
     * higher than the top of the stack, you know the day in the stack can never be the next greatest since they'll encounter the 
     * current day first. In that case remove all days smaller than current within the stack.
     *
     * https://leetcode.com/problems/daily-temperatures/discuss/1574806/C%2B%2B-EASY-standard-sol-oror-INTUITIVE-approach-with-DRY-RUN-oror-STACK-appraoch
     * -Focus on understanding the two cases if you comments arent enough.
    */
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> ans(temperatures.size(), 0);
        std::stack<int> indices;
        int n = temperatures.size()-1;
        indices.push(n);
        for(int i = n; i >= 0; --i)
        {
            while(!indices.empty() && temperatures[i] >= temperatures[indices.top()]) //if current temp is higher than those in stack, those in stack will never be the next warmer temp
            {
                indices.pop();
            }
            if(!indices.empty() && temperatures[i] < temperatures[indices.top()])
            {
                ans[i] = indices.top() - i;
            }
            indices.push(i);
        }
        return ans;
        
    }
};