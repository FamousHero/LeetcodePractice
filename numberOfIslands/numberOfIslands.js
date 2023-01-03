/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    let islands = 0;
    for(let i = 0; i < grid.length; ++i){
        for(let j = 0; j < grid[0].length; ++j){
            if(grid[i][j] === '1'){
                dfs(i, j, grid);
                ++islands;
            }
        }
    }
    return islands;
};

/**
 * @param {number, number, character[][]}
 * return {void}
*/
function dfs(i, j, grid){
    if(i < 0 || i >= grid.length ||
       j < 0 || j >= grid[0].length ||
       grid[i][j] === '0'){
        return;
    }
    grid[i][j] = '0';
    dfs(i-1, j, grid);
    dfs(i+1, j, grid);
    dfs(i, j+1, grid);
    dfs(i, j-1, grid);
    
}