class Solution {

    int solve(vector<int>& arr, int d, int index){
        int size=arr.size();


        int ans=1;
        int nextX=0;
        for(int step=1;step<=d;step++){


            int next=index+step;

            if(next>=size){
                break;
            }

            if(arr[index]<=arr[next]){
                break;
            }

            if(next<size){
                nextX=solve(arr, d, next);

                ans=max(ans, 1+nextX);
            }
        }


        int prevX=0;
         for(int step=1;step<=d;step++){

            int prev=index-step;

            if(prev<0){break;}

            if(arr[index]<=arr[prev]){
                break;
            }

            if(prev>=0){
                prevX=solve(arr, d, prev);
                ans=max(ans, 1+prevX);
            }
        }

        return ans;


        
    }

    int dpSolve(vector<int>& arr, int d, int index, vector<int>&dp){
        int size=arr.size();

        if(dp[index]!=-1){
            return dp[index];
        }


        int ans=1;
        int nextX=0;
        for(int step=1;step<=d;step++){


            int next=index+step;

            if(next>=size){
                break;
            }

            if(arr[index]<=arr[next]){
                break;
            }

            if(next<size){
                nextX=dpSolve(arr, d, next,dp);

                ans=max(ans, 1+nextX);
            }
        }


        int prevX=0;
         for(int step=1;step<=d;step++){

            int prev=index-step;

            if(prev<0){break;}

            if(arr[index]<=arr[prev]){
                break;
            }

            if(prev>=0){
                prevX=dpSolve(arr, d, prev,dp);
                ans=max(ans, 1+prevX);
            }
        }

        return dp[index]=ans;


        
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        
        // int maxi=0;
        // for(int i=0;i<arr.size();i++){
        //     maxi=max(maxi, solve(arr,d,i));
        // }
        // return maxi;



        //rec +memo
          int maxi=0;
          vector<int> dp(arr.size()+1,-1);
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi, dpSolve(arr,d,i,dp));
        }
        return maxi;
    }
};