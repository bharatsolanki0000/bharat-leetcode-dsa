class Solution {
    int solve(int n, int k, int target){

        if(target==0 && n==0){
            return 1;
        }

        if(target<=0 || n==0){
            return 0;
        }

        int ans=0;
        for(int i=1;i<=k;i++){
            ans+=solve(n-1,k,target-i);
        }

        return ans;

    
    }

    long long dpSolve(int n, int k, int target, vector<vector<long long>>&dp){
        if(target==0 && n==0){
            return 1;
        }

        if(target<=0 || n<=0){
            return 0;
        }

        if(dp[n][target]!=-1){
            return dp[n][target];
        }

        long long ans=0;
        for(int i=1;i<=k;i++){
            ans+=dpSolve(n-1,k,target-i,dp)%1000000007;
        }

        return dp[n][target]=ans%1000000007;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        //return solve(n,k,target);

        vector<vector<long long>> dp(n+1, vector<long long> (target+1, -1));
        return dpSolve(n,k,target, dp);
    }
};