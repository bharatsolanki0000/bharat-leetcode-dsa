class Solution {

    int solve(string s, int i, int j){
        if(i>j){
            return 0;
        }

        if(i==j){
            return 1;
        }

        int ans=0;
        if(s[i]==s[j]){
            ans=2+solve(s,i+1,j-1);
        }
        else{
            int moveI=solve(s,i+1,j);
            int moveJ=solve(s,i,j-1);
            ans=max(moveI,moveJ);
        }

        return ans;

    }

    
    int dpSolve(string s, int i, int j,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }

        if(i==j){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;
        if(s[i]==s[j]){
            ans=2+dpSolve(s,i+1,j-1,dp);
        }
        else{
            int moveI=dpSolve(s,i+1,j,dp);
            int moveJ=dpSolve(s,i,j-1,dp);
            ans=max(moveI,moveJ);
        }

        return dp[i][j]=ans;

    }

    int tabuSolve(string s){
        vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1,0));

        for(int i=s.length()-1;i>=0;i--){
            for(int j=i;j<=s.length()-1;j++){
                int ans=0;
                if(i==j){
                    ans=1;
                }
                else if(s[i]==s[j]){
                    ans=2+dp[i+1][j-1];
                }
                else{
                    int moveI=dp[i+1][j];
                    int moveJ=dp[i][j-1];
                    ans=max(moveI,moveJ);
                }
                dp[i][j]=ans;
            }
        }

        return dp[0][s.length()-1];
    }

    int soSolve(string s){
       vector<int> curr(s.length()+1,0);
       vector<int> next(s.length()+1,0);

        for(int i=s.length()-1;i>=0;i--){
            for(int j=i;j<=s.length()-1;j++){
                int ans=0;
                if(i==j){
                    ans=1;
                }
                else if(s[i]==s[j]){
                    ans=2+next[j-1];
                }
                else{
                    int moveI=next[j];
                    int moveJ=curr[j-1];
                    ans=max(moveI,moveJ);
                }
                curr[j]=ans;
            }
            next=curr;
        }

        return next[s.length()-1];
    }
public:
    int longestPalindromeSubseq(string s) {
        //return solve(s,0,s.length()-1);

        // vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1,-1));
        // return dpSolve(s,0,s.length()-1,dp);

        //return tabuSolve(s);

        return soSolve(s);
    }
};