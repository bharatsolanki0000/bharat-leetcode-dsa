class Solution {

    int solve(int n){
        
        if(n<=1){
            return 1;
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            int left=solve(i-1);
            int right=solve(n-i);
            ans+=left*right;    
        }
        
        return ans;
        

    }

    int dpSolve(int n ,vector<int>&dp){
        if(n<=1){
            return 1;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            int left=dpSolve(i-1,dp);
            int right=dpSolve(n-i,dp);
            ans+=left*right;    
        }
        
        return dp[n]=ans;
        
    }
public:
    int numTrees(int n) {
        //return solve(n);
        vector<int> dp(n+1, -1);
        return dpSolve(n,dp);
    }
};