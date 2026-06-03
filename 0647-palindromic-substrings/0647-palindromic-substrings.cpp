class Solution {

      bool check(int i, int j, string &s, vector<vector<int>> &dp){

        if(i>=j){
            return dp[i][j]=1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==s[j]){
            return dp[i][j]=check(i+1,j-1,s,dp);
        }

        return dp[i][j]=0;
    }
public:
    int countSubstrings(string s) {
        int ans=0;

       vector<vector<int>> dp(s.length()+1, vector<int> (s.length()+1, -1));

        for(int i=0;i<s.length();i++){

            for(int j=s.length()-1;j>=i;j--){

                if(check(i,j,s,dp)){
                    ans++;
                }
                
            }
        }
        return ans;
    }
};