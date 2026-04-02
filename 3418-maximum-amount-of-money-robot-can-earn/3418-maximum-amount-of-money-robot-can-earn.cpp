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

        int amount=INT_MIN;

        int right=solve(coins, row, col+1, rowSize, colSize, protect);
        int down=solve(coins, row+1, col, rowSize, colSize, protect);

        // RIGHT PATH
        if(right!=INT_MIN){

            if(coins[row][col]<0){
                if(protect>0){
                    amount = max(amount, solve(coins, row, col+1, rowSize, colSize, protect-1)); 
                }
              
                amount = max(amount, right + coins[row][col]);
            }
            else{
                amount = max(amount, right + coins[row][col]);
            }
        }

        // DOWN PATH
        if(down!=INT_MIN){

            if(coins[row][col]<0){
               
                if(protect>0){
                    amount = max(amount, solve(coins, row+1, col, rowSize, colSize, protect-1));
                }
                
                amount = max(amount, down + coins[row][col]);
            }
            else{
                amount = max(amount, down + coins[row][col]);
            }
        }

        return amount;
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

        int amount=INT_MIN;

        int right=dpSolve(coins, row, col+1, rowSize, colSize, protect,dp);
        int down=dpSolve(coins, row+1, col, rowSize, colSize, protect,dp);

        // RIGHT PATH
        if(right!=INT_MIN){

            if(coins[row][col]<0){
                if(protect>0){
                    amount = max(amount, dpSolve(coins, row, col+1, rowSize, colSize, protect-1,dp)); 
                }
              
                amount = max(amount, right + coins[row][col]);
            }
            else{
                amount = max(amount, right + coins[row][col]);
            }
        }

        // DOWN PATH
        if(down!=INT_MIN){

            if(coins[row][col]<0){
               
                if(protect>0){
                    amount = max(amount, dpSolve(coins, row+1, col, rowSize, colSize, protect-1,dp));
                }
                
                amount = max(amount, down + coins[row][col]);
            }
            else{
                amount = max(amount, down + coins[row][col]);
            }
        }

        return dp[row][col][protect]=amount;
    }

int tabuSolve(vector<vector<int>>& coins){
    int rowSize = coins.size(); 
    int colSize = coins[0].size();

    vector<vector<vector<int>>> dp(rowSize, vector<vector<int>>(colSize, vector<int>(3, INT_MIN)));
    
    
    for(int p = 0; p < 3; p++){
        if(coins[rowSize-1][colSize-1] < 0){
            if(p > 0) dp[rowSize-1][colSize-1][p] = 0;
            else dp[rowSize-1][colSize-1][p] = coins[rowSize-1][colSize-1];
        } else {
            dp[rowSize-1][colSize-1][p] = coins[rowSize-1][colSize-1];
        }
    }

   
    for(int row = rowSize-1; row >= 0; row--){
        for(int col = colSize-1; col >= 0; col--){

            if(row == rowSize-1 && col == colSize-1) continue;

            for(int protect = 0; protect < 3; protect++){

                int amount = INT_MIN;

                int right = (col+1 < colSize) ? dp[row][col+1][protect] : INT_MIN;
                int down  = (row+1 < rowSize) ? dp[row+1][col][protect] : INT_MIN;

                // 🔹 RIGHT
                if(right != INT_MIN){

                    if(coins[row][col] < 0){

                        // use protection
                        if(protect > 0){
                            int val = dp[row][col+1][protect-1];
                            if(val != INT_MIN)
                                amount = max(amount, val);
                        }

                        // don't use protection
                        amount = max(amount, right + coins[row][col]);
                    }
                    else{
                        amount = max(amount, right + coins[row][col]);
                    }
                }

                // 🔹 DOWN
                if(down != INT_MIN){

                    if(coins[row][col] < 0){

                        // use protection
                        if(protect > 0){
                            int val = dp[row+1][col][protect-1];
                            if(val != INT_MIN)
                                amount = max(amount, val);
                        }

                        // don't use protection
                        amount = max(amount, down + coins[row][col]);
                    }
                    else{
                        amount = max(amount, down + coins[row][col]);
                    }
                }

                dp[row][col][protect] = amount;
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
        //return solve(coins, 0,0, rowSize, colSize, protect);

        // vector<vector<vector<int>>> dp(rowSize+1, vector<vector<int>>(colSize+1, vector<int> (3,-1)));
        // return dpSolve(coins, 0,0, rowSize, colSize, protect, dp);

        return tabuSolve(coins);
    }
};