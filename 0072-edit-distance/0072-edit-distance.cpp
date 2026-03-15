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


    int tabuSolve(string word1, string word2){
        vector<vector<int>> dp(word1.length()+1, vector<int> (word2.length()+1, 0));

        //base
        for(int i=0;i<word1.size();i++){
            dp[i][word2.length()]=word1.length()-i;    
        }

        for(int j=0;j<word2.size();j++){
            dp[word1.length()][j]=word2.length()-j;
        }


        //word 1 of ith index
        for(int i=word1.length()-1;i>=0;i--){
            
            //jth for word2
            for(int j=word2.length()-1;j>=0;j--){

                int ans=0;
                if(word1[i]==word2[j]){
                    ans=dp[i+1][j+1];
                }
                else{
                    //INSERT
                    int insertChar=dp[i][j+1];
                    

                    //DELETE
                    int deleteChar=dp[i+1][j];
                    


                    //REPLACE
                    int replaceChar=dp[i+1][j+1];


                    ans=1+min({insertChar, replaceChar, deleteChar});

                    }

                    dp[i][j]=ans;

                }
        }

        return dp[0][0];
    }


     int soSolve(string word1, string word2){
        vector<int> curr(word2.length()+1,0);
        vector<int> next(word2.length()+1,0);

        

        for(int j=0;j<word2.size();j++){
            next[j]=word2.length()-j;
        }


        //word 1 of ith index
        for(int i=word1.length()-1;i>=0;i--){

            curr[word2.length()]=word1.length()-i;
            //jth for word2
            for(int j=word2.length()-1;j>=0;j--){

                int ans=0;
                if(word1[i]==word2[j]){
                    ans=next[j+1];
                }
                else{
                    //INSERT
                    int insertChar=curr[j+1];
                    

                    //DELETE
                    int deleteChar=next[j];
                    


                    //REPLACE
                    int replaceChar=next[j+1];


                    ans=1+min({insertChar, replaceChar, deleteChar});

                    }

                    curr[j]=ans;

                }
                next=curr;
        }

        return next[0];
    }


public:
    int minDistance(string word1, string word2) {
        //return solve(word1, word2, 0,0);

        //rec + memo
        //  vector<vector<int>> dp(word1.length()+1, vector<int> (word2.length()+1, -1));
        //  return dpSolve(word1,word2,0,0,dp);

        //tabulation
        //return tabuSolve(word1,word2);

        //space optimisation
        return soSolve(word1,word2);


    }
};



