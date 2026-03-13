class Solution {
       int solve(string text1, string text2, int i, int j){
        
        if(i==text1.size()|| j==text2.size()){
            return 0;
        }
        
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1+solve(text1,text2,i+1,j+1);
        }
        else{

            int moveI=solve(text1,text2,i+1,j);
            int moveJ=solve(text1,text2,i,j+1);

            ans=max(moveI,moveJ);
        }

        return ans;
    }


    int dpSolve(string text1, string text2, int i, int j,  vector<vector<int>> &dp){
        
        if(i==text1.size()|| j==text2.size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1+dpSolve(text1,text2,i+1,j+1,dp);
        }
        else{

            int moveI=dpSolve(text1,text2,i+1,j,dp);
            int moveJ=dpSolve(text1,text2,i,j+1,dp);

            ans=max(moveI,moveJ);
        }

        return dp[i][j]=ans;
    }

    int tabuSolve(string text1, string text2){
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1,0));

        for(int i=text1.length()-1;i>=0;i--){
            for(int j=text2.length()-1;j>=0;j--){
                
                int ans=0;
                if(text1[i]==text2[j]){
                    ans=1+dp[i+1][j+1];
                }
                else{

                    int moveI=dp[i+1][j];
                    int moveJ=dp[i][j+1];

                    ans=max(moveI,moveJ);
                }

                dp[i][j]=ans;
            }
        }

        return dp[0][0];

    }

     int soSolve(string text1, string text2){

       // vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1,0));
        vector<int> curr(text2.size()+1,0);
        vector<int> next(text2.size()+1,0);

        for(int i=text1.length()-1;i>=0;i--){
            for(int j=text2.length()-1;j>=0;j--){
                
                int ans=0;
                if(text1[i]==text2[j]){
                    ans=1+next[j+1];
                }
                else{

                    int moveI=next[j];
                    int moveJ=curr[j+1];

                    ans=max(moveI,moveJ);
                }

                curr[j]=ans;
            }
            next=curr;
        }

        return next[0];

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        //return solve(text1,text2,0,0);

        //rec +memo
        // vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1,-1));
        // return dpSolve(text1,text2,0,0,dp);

        //return tabuSolve(text1,text2);

        return soSolve(text1,text2);
    }
};