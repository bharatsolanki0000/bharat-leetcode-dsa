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

    int tabuSolve(vector<vector<int>>& grid, int K){
        int rowSize=grid.size();
        int colSize=grid[0].size();
      
        vector<vector<int>> temp={{1,0}, {0,1}};
        vector<vector<vector<int>>> dp(rowSize, vector<vector<int>>(colSize, vector<int >(K+1,0)));
        
       
        for(int row=rowSize-1;row>=0;row--){
            for(int col=colSize-1;col>=0;col--){

                dp[row][col][0]=INT_MIN;

                for(int k=0;k<=K;k++){

                    int currK = k;
                        if(row==rowSize-1 && col==colSize-1){
                        dp[row][col][k]=grid[row][col];
                        continue;
                        }

                    int ans=INT_MIN;
       
                    for(int i=0;i<2;i++){
                    
                        int tempX=row+temp[i][0];
                        int tempY=col+temp[i][1];

                        if( tempY>=colSize || tempX>=rowSize ){
                            continue;
                        }
                        int tempp=INT_MIN;

                    
                            if(grid[tempX][tempY]==0){
                                tempp=dp[tempX][tempY][k];
                            }
                            else{

                                if(k>0){
                                    tempp=dp[tempX][tempY][k-1];
                                }
                            
                            }  
                        

                        if(tempp!=INT_MIN){
                            ans=max(ans, grid[row][col]+tempp);
                        }

                    }
                    

                    dp[row][col][k]=ans;
                    
                }
            }
        }

        return dp[0][0][K];

    }
    int solve2(vector<vector<int>>& grid, int k,int cost, int row, int col){

        int rowSize=grid.size();
        int colSize=grid[0].size();

        if(row>=rowSize || col>=colSize){
            return INT_MIN;
        }

        int newCost=cost+(grid[row][col]>0);

        if(newCost>k){
            return INT_MIN;
        }

        if(row==rowSize-1 && col==colSize-1){
            return grid[row][col];
        }

    
        int right=solve2(grid, k, newCost, row, col+1);
        int down=solve2(grid, k, newCost, row+1,col);
        int bestAns=max(right, down);


        if(bestAns!=INT_MIN){
            return grid[row][col]+bestAns;
        }
        return INT_MIN;
    }



     int dpSolve2(vector<vector<int>>& grid, int k,int cost, int row, int col,vector<vector<vector<int>>> &dp){


         int rowSize=grid.size();
        int colSize=grid[0].size();

        if(row>=rowSize || col>=colSize){
            return INT_MIN;
        }

        int newCost=cost+(grid[row][col]>0);

        if(newCost>k){
            return INT_MIN;
        }

        if(row==rowSize-1 && col==colSize-1){
            return grid[row][col];
        }

           
        if(dp[row][col][cost]!=-1){ 
            return dp[row][col][cost];
        }


    
        int right=dpSolve2(grid, k, newCost, row, col+1,dp);
        int down=dpSolve2(grid, k, newCost, row+1,col,dp);
        int bestAns=max(right, down);


        if(bestAns!=INT_MIN){
            return dp[row][col][cost]=grid[row][col]+bestAns;
        }
        return dp[row][col][cost]=INT_MIN;

       
    }

    int tabuSolve2(vector<vector<int>>& grid, int k){
    int rowSize = grid.size();
    int colSize = grid[0].size();

    vector<vector<vector<int>>> dp(
        rowSize, vector<vector<int>>(colSize, vector<int>(k+1, INT_MIN))
    );

    for(int row = rowSize-1; row >= 0; row--){
        for(int col = colSize-1; col >= 0; col--){
            for(int cost = k; cost >= 0; cost--){

                int newCost = cost + (grid[row][col]>0);

                if(newCost > k) continue;

                // Base case
                if(row == rowSize-1 && col == colSize-1){
                    dp[row][col][cost] = grid[row][col];
                    continue;
                }

                int right = INT_MIN;
                int down  = INT_MIN;

                if(row + 1 < rowSize){
                    down = dp[row+1][col][newCost];
                }

                if(col + 1 < colSize){
                    right = dp[row][col+1][newCost];
                }

                int bestAns = max(right, down);

                if(bestAns != INT_MIN){
                    dp[row][col][cost] = grid[row][col] + bestAns;
                }
            }
        }
    }

    return dp[0][0][0];
}
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int rowSize=grid.size();
        int colSize=grid[0].size();
      
       // vector<vector<int>> temp={{1,0}, {0,1}};
        //rec
        // int result=solve(grid, k,temp, 0,0);
        // return result!=INT_MIN?result:-1;


        //rec + memo
        // vector<vector<vector<int>>> dp(rowSize+1, vector<vector<int>>(colSize+1, vector<int >(k+1,-1)));
        // int result=dpSolve(grid, k,temp, 0,0,dp);
        // return result!=INT_MIN?result:-1;

        //tabu
        // int result=tabuSolve(grid, k);
        // return result!=INT_MIN?result:-1;







        // REC
        // int result=solve2(grid, k,0, 0,0);
        // return result!=INT_MIN?result:-1;

       // rec + memo
        // vector<vector<vector<int>>> dp(rowSize+1, vector<vector<int>>(colSize+1, vector<int >(k+1,-1)));
        // int result=dpSolve2(grid, k,0, 0,0,dp);
        // return result!=INT_MIN?result:-1;

        
        //tabu
        int result=tabuSolve2(grid, k);
        return result!=INT_MIN?result:-1;





    }
};