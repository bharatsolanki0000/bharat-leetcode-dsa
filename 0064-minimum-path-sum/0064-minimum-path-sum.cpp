class Solution {
    int solve(int row, int col,vector<vector<int>>& grid){

        int rowSize=grid.size();
        int colSize=grid[0].size();

        if(row==rowSize || col==colSize){
            return INT_MAX;
        }
        int down=0;
        down=solve(row+1,col, grid);

        int right=0;
        right=solve(row, col+1, grid);

        if(down==INT_MAX && right==INT_MAX){
            return grid[row][col];
        }
        return grid[row][col]+min(down, right);
    }

    int dpSolve(int row, int col,vector<vector<int>>& grid, vector<vector<int>> &dp){

        int rowSize=grid.size();
        int colSize=grid[0].size();

        if(row==rowSize || col==colSize){
            return INT_MAX;
        }

        if(dp[row][col]!=INT_MAX){
            return dp[row][col];
        }

        int down=0;
        down=dpSolve(row+1,col, grid,dp);

        int right=0;
        right=dpSolve(row, col+1, grid,dp);

        if(down==INT_MAX && right==INT_MAX){
            return dp[row][col]=grid[row][col];
        }
        return dp[row][col]=grid[row][col]+min(down, right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
       //return solve(0,0,grid);

        //rec +memo
        int rowSize=grid.size();
        int colSize=grid[0].size();
        vector<vector<int>> dp(rowSize+1, vector<int>(colSize+1, INT_MAX));
        return dpSolve(0,0,grid,dp);
    }
};