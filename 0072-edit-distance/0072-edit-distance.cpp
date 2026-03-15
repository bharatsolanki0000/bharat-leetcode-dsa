class Solution {

    int solve(string word1, string word2, int i, int j){

        if(j==word2.length()){
            return word1.length()-i;
        }

        if(i==word1.length()){
            return word2.length()-j; 
        }

        int ans=0;
        if(word1[i]==word2[j]){
            ans=solve(word1,word2,i+1,j+1);
        }
        else{
             //INSERT
            int insertChar=solve(word1,word2,i,j+1);
            

            //DELETE
            int deleteChar=solve(word1,word2,i+1,j);
            


            //REPLACE
            int replaceChar=solve(word1,word2,i+1,j+1);



            ans=1+min({insertChar, replaceChar, deleteChar});

            }

            return ans;

    }

    int dpSolve(string word1, string word2, int i, int j, vector<vector<int>> &dp){

        if(j==word2.length()){
            return word1.length()-i;
        }

        if(i==word1.length()){
            return word2.length()-j; 
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;
        if(word1[i]==word2[j]){
            ans=dpSolve(word1,word2,i+1,j+1,dp);
        }
        else{
             //INSERT
            int insertChar=dpSolve(word1,word2,i,j+1,dp);
            

            //DELETE
            int deleteChar=dpSolve(word1,word2,i+1,j,dp);
            


            //REPLACE
            int replaceChar=dpSolve(word1,word2,i+1,j+1,dp);



            ans=1+min({insertChar, replaceChar, deleteChar});

            }

            return dp[i][j]=ans;

    }
public:
    int minDistance(string word1, string word2) {
        //return solve(word1, word2, 0,0);

        //rec + memo
        vector<vector<int>> dp(word1.length()+1, vector<int> (word2.length(), -1));
        return dpSolve(word1,word2,0,0,dp);
    }
};



