var twoSum = function(nums, target) {
    let map = new Map();
    
    for(let i = 0; i < nums.length; i ++) {
        let base = nums[i];
        if(map.has(base)) {
            return [map.get(base), i];
        } else {
            map.set(target - base, i);
        }
    }
	return [];
};