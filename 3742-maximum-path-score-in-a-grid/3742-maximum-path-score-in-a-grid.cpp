class Solution {

    int solve(vector<vector<int>>& grid, int k, vector<vector<int>>& temp, int row, int col){
        int rowSize=grid.size();
        int colSize=grid[0].size();

        if(k < 0) return INT_MIN;

        if(row==rowSize-1 && col==colSize-1){
            
            return grid[row][col];
            

        }

        int ans=INT_MIN;
       
        for(int i=0;i<2;i++){
           
            int tempX=row+temp[i][0];
            int tempY=col+temp[i][1];

            if(tempX<0 || tempY<0 || tempY>=colSize || tempX>=rowSize ){
                continue;
            }
             int tempp=INT_MIN;

        
                if(grid[tempX][tempY]==0){
                    tempp=solve(grid, k, temp, tempX, tempY);
                }
                else{

                    if(k>0){
                        tempp=solve(grid,k-1, temp,tempX, tempY);
                    }
                  
                }  
            

            if(tempp!=INT_MIN){
                ans=max(ans, grid[row][col]+tempp);
            }

        }
        

        return ans;
        
        
    }

    
    int dpSolve(vector<vector<int>>& grid, int k, vector<vector<int>>& temp, int row, int col,  vector<vector<vector<int>>> &dp){
        int rowSize=grid.size();
        int colSize=grid[0].size();

        if(k < 0) return INT_MIN;

        if(row==rowSize-1 && col==colSize-1){
            return grid[row][col];
        }

        if(dp[row][col][k]!=-1){ 
            return dp[row][col][k];
        }

        int ans=INT_MIN;
       
        for(int i=0;i<2;i++){
           
            int tempX=row+temp[i][0];
            int tempY=col+temp[i][1];

            if(tempX<0 || tempY<0 || tempY>=colSize || tempX>=rowSize ){
                continue;
            }
             int tempp=INT_MIN;

        
                if(grid[tempX][tempY]==0){
                    tempp=dpSolve(grid, k, temp, tempX, tempY,dp);
                }
                else{

                    if(k>0){
                        tempp=dpSolve(grid,k-1, temp,tempX, tempY,dp);
                    }
                  
                }  
            

            if(tempp!=INT_MIN){
                ans=max(ans, grid[row][col]+tempp);
            }

        }
        

        return dp[row][col][k]=ans;
        
        
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int rowSize=grid.size();
        int colSize=grid[0].size();
      
        vector<vector<int>> temp={{1,0}, {0,1}};
        
        //rec
        // int result=solve(grid, k,temp, 0,0);
        // return result!=INT_MIN?result:-1;


        //rec + memo
        vector<vector<vector<int>>> dp(rowSize+1, vector<vector<int>>(colSize+1, vector<int >(k+1,-1)));
        int result=dpSolve(grid, k,temp, 0,0,dp);
        return result!=INT_MIN?result:-1;

    }
};