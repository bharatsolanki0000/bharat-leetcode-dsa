class Solution {

    int solve(vector<int>& prices, bool canBuy, int index){

        if(index==prices.size()){
            return 0;
        }
        
        int profit=0;

        if(canBuy){
            //buy
            int buy=-prices[index]+solve(prices, false, index+1);
            //ignore
            int ignoreBuy=solve(prices,true,index+1);
            profit=max(buy,ignoreBuy);
        }
        else{
            //sell
            int sell=prices[index]+solve(prices, true,index+1);
            int ignoreSell=solve(prices,false, index+1);
            profit=max(sell, ignoreSell);
        }

        return profit;
        
    }
    int dpSolve(vector<int>& prices, int canBuy, int index, vector<vector<int>> &dp){

        if(index==prices.size()){
            return 0;
        }

        if(dp[index][canBuy]!=-1){
            return dp[index][canBuy];
        }
        
        int profit=0;

        if(canBuy){
            //buy
            int buy=-prices[index]+dpSolve(prices, 0, index+1,dp);
            //ignore
            int ignoreBuy=dpSolve(prices,1,index+1,dp);
            profit=max(buy,ignoreBuy);
        }
        else{
            //sell
            int sell=prices[index]+dpSolve(prices, 1,index+1,dp);
            int ignoreSell=dpSolve(prices,0, index+1,dp);
            profit=max(sell, ignoreSell);
        }

        return dp[index][canBuy]=profit;
        
    }

    int tabuSolve(vector<int>& prices){
         vector<vector<int>> dp(prices.size()+1, vector<int> (2,0));

         for(int index=prices.size()-1;index>=0;index--){
            for(int canBuy=1;canBuy>=0;canBuy--){

                int profit=0;
                if(canBuy){
                    //buy
                    int buy=-prices[index]+dp[index+1][0];
                    //ignore
                    int ignoreBuy=dp[index+1][1];
                    profit=max(buy,ignoreBuy);
                }
                else{
                    //sell
                    int sell=prices[index]+dp[index+1][1];
                    int ignoreSell=dp[index+1][0];
                    profit=max(sell, ignoreSell);
                }
                dp[index][canBuy]=profit;
            }
         }
         return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices) {
        
        //return solve(prices, true,0);
        
        // vector<vector<int>> dp(prices.size()+1, vector<int> (2,-1));
        // return dpSolve(prices, true, 0, dp);

        return tabuSolve(prices);
    }
};