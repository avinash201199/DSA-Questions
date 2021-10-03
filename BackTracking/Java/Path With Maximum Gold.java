// LC-1219

class Solution {
    public int getMaximumGold(int[][] grid) {
        for(int i=0;i<grid.length;i++) {
            for(int j=0;j<grid[0].length;j++) {
                if(grid[i][j]!=0) {
                    paths(grid,i,j,new boolean[grid.length][grid[0].length], 0);
                }
            }
        }
        return ans;
    }
    
    public int ans = Integer.MIN_VALUE;
    
    public void paths(int[][] grid, int row, int col, boolean[][] visited, int gold) {
        
        ans = Math.max(ans,gold);
        
        if(row<0 || col<0 || row>=grid.length || col>=grid[0].length || visited[row][col] == true || grid[row][col] == 0) {
            return;
        }
        
        visited[row][col] = true;
        paths(grid,row,col+1,visited,gold+grid[row][col]);
        paths(grid,row,col-1,visited,gold+grid[row][col]);
        paths(grid,row+1,col,visited,gold+grid[row][col]);
        paths(grid,row-1,col,visited,gold+grid[row][col]);
        visited[row][col] = false;
    }
    
}
