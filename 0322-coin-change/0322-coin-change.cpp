class Solution {

    int solve(vector<int>& coins, int amount){
        if(amount==0){
            return 0;
        }

        if(amount<0){
            return INT_MAX;
        }


            int ans=INT_MAX;
            for(auto coin: coins){

                int tempAns=solve(coins, amount-coin);
                if(tempAns!=INT_MAX){
                    ans=min(ans,1+ tempAns);
                }

            }
            return ans;
        

    }

    int dpSolve(vector<int>& coins, int amount, vector<int>&dp){

        if(amount==0){
            return 0;
        }

        if(amount<0){
            return INT_MAX;
        }

        if(dp[amount]!=-1){
            return dp[amount];
        }


            int ans=INT_MAX;
            for(int i=0;i<coins.size();i++){

                int tempAns=dpSolve(coins, amount-coins[i],dp);
                if(tempAns!=INT_MAX){
                    ans=min(ans,1+ tempAns);
                }

            }
            return dp[amount]=ans;
        

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // int result=solve(coins, amount);

        // return result==INT_MAX?-1:result;

        vector<int> dp(amount+1, -1);
        int result=dpSolve(coins, amount,dp);
        return result==INT_MAX?-1:result;
    }
};