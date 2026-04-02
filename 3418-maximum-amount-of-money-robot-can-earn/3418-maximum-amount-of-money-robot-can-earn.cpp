class Solution {

int solve(vector<vector<int>>& coins, int row, int col, int &rowSize, int &colSize, int protect){

      if(row==rowSize-1 && col==colSize-1){

            if(protect>0 && coins[row][col]<0){
                return 0;
            }
            return coins[row][col];
      }

      if(row==rowSize || col==colSize){
        return INT_MIN;
      }

        int skipCoin=INT_MIN;
        int takeCoin=INT_MIN;

        //TAKE
        int takeRight=solve(coins, row, col+1, rowSize, colSize,protect);
        int takeDown=solve(coins, row+1, col, rowSize, colSize, protect);
        takeCoin=coins[row][col]+max(takeRight, takeDown);

        //skip 
        if(coins[row][col]<0 && protect>0){
             int skipRight=solve(coins, row, col+1, rowSize, colSize,protect-1);
             int skipDown=solve(coins, row+1, col, rowSize, colSize, protect-1);

             skipCoin=max(skipRight, skipDown);
        }
        
        return max(takeCoin, skipCoin);

        
    }

    
int dpSolve(vector<vector<int>>& coins, int row, int col, int &rowSize, int &colSize, int protect, vector<vector<vector<int>>> &dp){

       if(row==rowSize-1 && col==colSize-1){

            if(protect>0 && coins[row][col]<0){
                return 0;
            }
            return coins[row][col];
      }

      if(row==rowSize || col==colSize){
        return INT_MIN;
      }

      if(dp[row][col][protect]!=-1){
        return dp[row][col][protect];
      }

        int skipCoin=INT_MIN;
        int takeCoin=INT_MIN;

        //TAKE
        int takeRight=dpSolve(coins, row, col+1, rowSize, colSize,protect,dp);
        int takeDown=dpSolve(coins, row+1, col, rowSize, colSize, protect,dp);
        takeCoin=coins[row][col]+max(takeRight, takeDown);

        //skip 
        if(coins[row][col]<0 && protect>0){
             int skipRight=dpSolve(coins, row, col+1, rowSize, colSize,protect-1,dp);
             int skipDown=dpSolve(coins, row+1, col, rowSize, colSize, protect-1,dp);

             skipCoin=max(skipRight, skipDown);
        }
        
        return dp[row][col][protect]=max(takeCoin, skipCoin);

        
    }

int tabuSolve(vector<vector<int>>& coins){
    int rowSize = coins.size(); 
    int colSize = coins[0].size();

    vector<vector<vector<int>>> dp(rowSize+1, vector<vector<int>>(colSize+1, vector<int>(3, INT_MIN)));
    
    
    for(int p=0;p<3;p++){
        if(coins[rowSize-1][colSize-1] <0 && p>0){
            dp[rowSize-1][colSize-1][p]=0;
        }
        else{
             dp[rowSize-1][colSize-1][p]=coins[rowSize-1][colSize-1];
        }
    }

   
    for(int row = rowSize-1; row >= 0; row--){
        for(int col = colSize-1; col >= 0; col--){

            if(row == rowSize-1 && col == colSize-1) continue;

            for(int protect = 0; protect < 3; protect++){

                    
                int skipCoin=INT_MIN;
                int takeCoin=INT_MIN;

                //TAKE
                int takeRight=dp[row][col+1][protect];
                int takeDown=dp[row+1][col][protect]; 
                takeCoin=coins[row][col]+max(takeRight, takeDown);

                //skip 
                if(coins[row][col]<0 && protect>0){
                    int skipRight=dp[row][col+1][protect-1];
                    int skipDown=dp[row+1][col][protect-1];

                    skipCoin=max(skipRight, skipDown);
                }
                
                dp[row][col][protect]=max(takeCoin, skipCoin);

            }
        }
    }

    return dp[0][0][2];
}

public:
    int maximumAmount(vector<vector<int>>& coins) {

        int rowSize=coins.size(); 
        int colSize=coins[0].size();

        int protect=2;
      //  return solve(coins, 0,0, rowSize, colSize, protect);

        // vector<vector<vector<int>>> dp(rowSize+1, vector<vector<int>>(colSize+1, vector<int> (3,-1)));
        // return dpSolve(coins, 0,0, rowSize, colSize, protect, dp);

        return tabuSolve(coins);
    }
};