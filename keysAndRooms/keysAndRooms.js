/**
 * @param {number[][]} rooms
 * @return {boolean}
 */
var canVisitAllRooms = function(rooms) {
    /** array.push() and array.pop() work the same as a stack
     *  so just use that meaning DFS search
     */
    let visited = new Array(rooms.length).fill(0);
    let stack = [];
    stack.push(0);
    visited[0] = 1;
    let roomsVisited = 1;
    while(stack.length !== 0){
        if(rooms.length === roomsVisited)
            return true;
        let room = stack.pop();
        ++roomsVisited;
        visited[room] = 1;
        rooms[room].forEach((key)=>{
            if(visited[key] === 0){
                stack.push(key);
            }
        });
    }
    return false;
};