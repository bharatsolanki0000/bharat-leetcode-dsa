class Solution {

    bool solve(string &s, string &p, int i, int j){
        if(i==s.length() && j==p.length()){
            return true;
        }

        if(i==s.length() && j<p.length()){

            for(int k=j;k<p.length();k++){
                if(p[k]!='*'){
                    //valid
                    return false;
                }
            }
            return true;
        }

        if(j==p.length() && i<s.length()){
            return false;
        }


        bool ans=false;
        if(s[i]==p[j] || p[j]=='?'){
            ans=solve(s,p,i+1,j+1);
        }
        else if(p[j]=='*'){
            bool letEmpty=solve(s,p,i,j+1);
            bool letChar=solve(s,p,i+1,j);

            ans=letEmpty || letChar;
        }

        return ans;
    }


    bool dpSolve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i==s.length() && j==p.length()){
            return true;
        }

        if(i==s.length() && j<p.length()){

            for(int k=j;k<p.length();k++){
                if(p[k]!='*'){
                    //valid
                    return false;
                }
            }
            return true;
        }

        if(j==p.length() && i<s.length()){
            return false;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }


        bool ans=false;
        if(s[i]==p[j] || p[j]=='?'){
            ans=dpSolve(s,p,i+1,j+1,dp);
        }
        else if(p[j]=='*'){
            bool letEmpty=dpSolve(s,p,i,j+1,dp);
            bool letChar=dpSolve(s,p,i+1,j,dp);

            ans=letEmpty || letChar;
        }

        return dp[i][j]=ans;
    }



public:
    bool isMatch(string s, string p) {
        //return solve(s,p,0,0);

        //rec +memo
        vector<vector<int>> dp(s.length()+1, vector<int> (p.length()+1,-1));
        return dpSolve(s,p,0,0,dp);
    }
};