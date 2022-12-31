#include <vector>
/**Pretty self explanatory. Any solution will be O(n) but
 * you can optimize the algorithm per each number. This solution
 * is O(32*n) since max possible shifts are 32.
 * 
 * 
 * To get better solutions, draw out the bits for a couple numbers and find the pattern
 * https://leetcode.com/problems/counting-bits/discuss/656551/C%2B%2B-With-Explanation-2-Different-Solutions-(4ms-99Time)
 * this Sol 2 is better since inner alg becomes O(m) where m is
 * the number of 1 bits rather than including 0s inbetween
 * 
 * https://leetcode.com/problems/counting-bits/discuss/800456/C%2B%2B-or-Counting-Bits-or-O(N)-Explanation
 * Best solution since inner algo becomes O(1). vector lookup is O(1)
 * and mod 2 is O(1) since its just checking the 1st bit. /(div) 2 is also
 * O(1) since its just >> 1. 
*/
class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> ans;
        for(int i = 0; i <= n; ++i)
        {
            int temp = i;
            int bits = 0;
            while(temp > 0)
            {
                bits += temp & 1;
                temp >>= 1;
            }
            ans.push_back(bits);
            
        }
        return ans;
    }
};