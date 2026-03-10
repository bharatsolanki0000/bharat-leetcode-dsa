class Solution {

    int solve(vector<int>&prices, int index, int buy, int limit){
        int n=prices.size();
        if(index==n){
            return 0;
        }

        if(limit==0){
            return 0;
        }

        int profit=0;
        if(buy==1){
            //buy or ignore
            int buyStock=-prices[index]+solve(prices, index+1, 0,limit);
            int ignoreBuy=solve(prices, index+1,1,limit);
            profit=max(buyStock,ignoreBuy);
        }
        else{
            //sell of ignore
            int sellStock=prices[index]+solve(prices, index+1, 1,limit-1);
            int ignoreSell=solve(prices, index+1,0,limit);
            profit=max(sellStock,ignoreSell);
        }
        return profit;
    }

    
    int dpSolve(vector<int>&prices, int index, int buy, int limit,vector<vector<vector<int>>> &dp){
        int n=prices.size();
        if(index==n){
            return 0;
        }

        if(limit==0){
            return 0;
        }

        if(dp[index][buy][limit]!=-1){
            return dp[index][buy][limit];
        }

        int profit=0;
        if(buy==1){
            //buy or ignore
            int buyStock=-prices[index]+dpSolve(prices, index+1, 0,limit,dp);
            int ignoreBuy=dpSolve(prices, index+1,1,limit,dp);
            profit=max(buyStock,ignoreBuy);
        }
        else{
            //sell of ignore
            int sellStock=prices[index]+dpSolve(prices, index+1, 1,limit-1,dp);
            int ignoreSell=dpSolve(prices, index+1,0,limit,dp);
            profit=max(sellStock,ignoreSell);
        }
        return dp[index][buy][limit]=profit;
    }

    int tabuSolve(vector<int>& prices){
         vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>> (2,vector<int> (3,0)));

            int n=prices.size();
         for(int index=n-1;index>=0;index--){

            for(int buy=0;buy<=1;buy++){

                for(int limit=1;limit<=2;limit++){
                      int profit=0;
                        if(buy==1){
                            //buy or ignore
                            int buyStock=-prices[index]+dp[index+1][0][limit];
                            int ignoreBuy=dp[index+1][1][limit];
                            profit=max(buyStock,ignoreBuy);
                        }
                        else{
                            //sell of ignore
                            int sellStock=prices[index]+dp[index+1][1][limit-1];
                            int ignoreSell=dp[index+1][0][limit];
                            profit=max(sellStock,ignoreSell); 
                        }
                       dp[index][buy][limit]=profit;
                }
            }
         }

         return dp[0][1][2];
    }

     int soSolve(vector<int>& prices){
         vector<vector<int>> curr(2, vector<int> (3,0));
          vector<vector<int>> next(2, vector<int> (3,0));

            int n=prices.size();
         for(int index=n-1;index>=0;index--){

            for(int buy=0;buy<=1;buy++){

                for(int limit=1;limit<=2;limit++){
                      int profit=0;
                        if(buy==1){
                            //buy or ignore
                            int buyStock=-prices[index]+next[0][limit];
                            int ignoreBuy=next[1][limit];
                            profit=max(buyStock,ignoreBuy);
                        }
                        else{
                            //sell of ignore
                            int sellStock=prices[index]+next[1][limit-1];
                            int ignoreSell=next[0][limit];
                            profit=max(sellStock,ignoreSell); 
                        }
                       curr[buy][limit]=profit;
                }
            }
            next=curr;
         }

         return next[1][2];
    }
public:
    int maxProfit(vector<int>& prices) {
       //return solve(prices, 0,1,2);

    //    vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>> (2,vector<int> (3,-1)));

    //    return dpSolve(prices,0,1,2,dp);

        //return tabuSolve(prices);
        return soSolve(prices);
    }
};