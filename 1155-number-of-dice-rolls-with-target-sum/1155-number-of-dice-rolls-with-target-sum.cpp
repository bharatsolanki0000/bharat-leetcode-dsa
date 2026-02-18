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
            ans+=dpSolve(n-1,k,target-i,dp);
        }

        return dp[n][target]=ans%1000000007;
    }

    int tabuSolve(int N, int K, int Target){

    vector<vector<long long>> dp(N+1, vector<long long> (Target+1, 0));
    dp[0][0]=1;
       for(int n=1;n<=N;n++){
            for(int target=1;target<=Target;target++){
                long long ans=0;
                for(int k=1;k<=K;k++){
                    if(target-k>=0){
                        ans+=dp[n-1][target-k];
                    }
                }
                dp[n][target]=ans%1000000007;
            }
       }
       return dp[N][Target];
    }

    int soSolve(int N, int K, int Target){

        //dp(n) dependds on n-1, target-k
        vector<long long > prev(Target+1, 0);
        vector<long long> curr(Target+1,0);
        prev[0]=1;

        for(int n=1;n<=N;n++){
            for(int target=1;target<=Target;target++){
                long long ans=0;
                for(int k=1;k<=K;k++){
                    if(target-k>=0){
                        ans+=prev[target-k];
                    }
                }
                curr[target]=ans%1000000007;
            }
            prev=curr;
       }
       return curr[Target];
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        //return solve(n,k,target);

        //rec +memo
        // vector<vector<long long>> dp(n+1, vector<long long> (target+1, -1));
        // return dpSolve(n,k,target, dp);

        //tab
        //return tabuSolve(n, k, target);

        //SO
        return soSolve(n,k,target);
    }
};