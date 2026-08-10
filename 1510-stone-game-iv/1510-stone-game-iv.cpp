class Solution {
    
    bool solve(int n){

        if(n==0){
            return false;
        }

        for(int i=1;i*i<=n;i++){

            if(!solve(n-i*i)){
                return true;
            }
        }

        return false;
    }

     bool dpSolve(int n, vector<int>&dp){

        if(n==0){
            return dp[n]=false;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        for(int i=1;i*i<=n;i++){

            if(!dpSolve(n-i*i,dp)){
                return dp[n]=true;
            }
        }

        return dp[n]=false;
    }
public:
    bool winnerSquareGame(int n) {
        //return solve(n);      

        vector<int> dp(n+1,-1);
        return dpSolve(n,dp);
    }
};