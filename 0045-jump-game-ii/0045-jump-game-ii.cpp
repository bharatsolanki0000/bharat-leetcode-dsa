class Solution {

    int solve(vector<int>& nums, int index){
        if(index>=nums.size()-1){
            return 0;
        }

        int steps=INT_MAX;

        for(int i=index+1;i<=index+nums[index];i++){
            
            
            int tempSteps=solve(nums,i);

            if(tempSteps!=INT_MAX){
                steps=min(steps, 1+tempSteps);
            }

        }

        return steps;


    }

    int dpSolve(vector<int>& nums, int index, vector<int>&dp){
        if(index>=nums.size()-1){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        int steps=INT_MAX;

        for(int i=index+1;i<=index+nums[index];i++){
            
            
            int tempSteps=dpSolve(nums,i,dp);

            if(tempSteps!=INT_MAX){
                steps=min(steps, 1+tempSteps);
            }

        }

        return dp[index]=steps;


    }


    int tabuSolve(vector<int>&nums){

        vector<int> dp(nums.size(),INT_MAX);

        dp[nums.size()-1]=0;

        for(int index=nums.size()-2;index>=0;index--){
              int steps=INT_MAX;
                for(int i=index+1;i<=index+nums[index];i++){
                    

                    int tempSteps=INT_MAX;

                    if(i< nums.size()){
                        tempSteps=dp[i];
                    }  

                    if(tempSteps!=INT_MAX){
                        steps=min(steps, 1+tempSteps);
                    }

                }
                 dp[index]=steps;
        }
        return dp[0];
    }

    int greedySolve(vector<int>& nums){

        int l=0;
        int r=0;
        int steps=0;
        

        while(r<nums.size()-1){
            int farthest=0;

            for(int i=l;i<=r;i++){
                farthest=max(farthest, i+nums[i]);
            }

            l=r+1;
            steps++;
            r=farthest;
        }
    return steps;

    }

public:
    int jump(vector<int>& nums) {

        if(nums.size()==1){
            return 0;
        }
        //return solve(nums,0);

        // vector<int> dp(nums.size(),-1);
        // return dpSolve(nums,0,dp);

        //return tabuSolve(nums);
        return greedySolve(nums);
    }
};