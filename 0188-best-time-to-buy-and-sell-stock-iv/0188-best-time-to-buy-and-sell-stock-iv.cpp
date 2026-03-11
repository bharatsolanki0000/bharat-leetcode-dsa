class Solution {

    int solve(int k, vector<int>& prices, int index, int buy){
        int n=prices.size();
        if(index==n){
            return 0;
        }

        if(k==0){
            return 0;
        }
        int profit=0;

        if(buy){
            //buy

            int buyStock=-prices[index]+solve(k,prices,index+1,0);

            int ignoreBuy=solve(k,prices,index+1,1);

            profit=max(buyStock,ignoreBuy);
        }
        else{
            //sell

            int sellStock=prices[index]+solve(k-1,prices,index+1,1);

            int ignoreSell=solve(k,prices,index+1,0);

            profit=max(sellStock,ignoreSell);
        }

        return profit;
    }

    
    int dpSolve(int k, vector<int>& prices, int index, int buy,  vector<vector<vector<int>>> &dp){
        int n=prices.size();
        if(index==n){
            return 0;
        }

        if(k==0){
            return 0;
        }

        if(dp[index][buy][k]!=-1){ 
            return dp[index][buy][k];
        }
        int profit=0;

        if(buy){
            //buy

            int buyStock=-prices[index]+dpSolve(k,prices,index+1,0,dp);

            int ignoreBuy=dpSolve(k,prices,index+1,1,dp);

            profit=max(buyStock,ignoreBuy);
        }
        else{
            //sell

            int sellStock=prices[index]+dpSolve(k-1,prices,index+1,1,dp);

            int ignoreSell=dpSolve(k,prices,index+1,0,dp);

            profit=max(sellStock,ignoreSell);
        }

        return dp[index][buy][k]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        //return solve(k,prices,0,1);

        vector<vector<vector<int>>> dp(prices.size()+1,
        vector<vector<int>>
         (2, vector<int> (k+1, -1)));
         return dpSolve(k,prices,0,1,dp);
    }
};