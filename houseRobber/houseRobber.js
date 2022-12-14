/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    let ans = nums[0];
    if(nums.length == 1)
        return ans;
    ans = Math.max(ans, nums[1]);
    nums[1] = ans;
    for(let i = 2; i < nums.length; ++i){
        ans = Math.max(nums[i-2] + nums[i], ans);
        nums[i] = ans;
    }
    return ans;
};