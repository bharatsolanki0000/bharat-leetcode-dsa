class Solution {

    int solve(int start, int end){
        if(start>=end){
            return 0;
        }

        int maxi=INT_MAX;
        for(int i=start;i<=end;i++){
            int lower=i+solve(start,i-1);
            int higher=i+solve(i+1,end);

            int tempMaxi=max(lower,higher);
            maxi=min(maxi,tempMaxi);
        }
        return maxi;
    }

    int dpSolve(int start, int end, vector<vector<int>>&dp){
        if(start>=end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }

        int maxi=INT_MAX;
        for(int i=start;i<=end;i++){
            int lower=i+dpSolve(start,i-1,dp);
            int higher=i+dpSolve(i+1,end,dp);

            int tempMaxi=max(lower,higher);
            maxi=min(maxi,tempMaxi);
        }
        return dp[start][end]=maxi;
    }
public:
    int getMoneyAmount(int n) {
       // return solve(1,n);

       vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
       return dpSolve(1,n,dp);
    }
};