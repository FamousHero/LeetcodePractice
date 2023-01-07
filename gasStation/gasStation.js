/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    let tank = 0, start = 0, total = 0;
    for(let i = 0; i < gas.length; ++i){
        const diff = gas[i] - cost[i];
        total += diff;
        tank += diff;
        if(tank < 0){
            tank = 0;
            start = i+1;
        }
    }
    if(total >= 0)
        return start;
    return -1;
};