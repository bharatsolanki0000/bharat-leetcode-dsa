class Solution {

    bool solve(vector<int>& nums, int index){

        if(index==nums.size()-1){
            return true;
        }

        if(index>=nums.size()){
            return false;
        }


        for(int i=index+1;i<=index+nums[index];i++){

            if(solve(nums,i)){
                return true;
            }
        }

        return false;
    }

    bool dpSolve(vector<int>& nums, int index, vector<int>&dp){

        if(index==nums.size()-1){
            return true;
        }

        if(index>=nums.size()){
            return false;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        bool ans=false;
        for(int i=index+1;i<=index+nums[index];i++){

            if(dpSolve(nums,i,dp)){
                ans= true;
                break;
            }
        }

        return dp[index]=ans;
        
    }

    int tabuSolve(vector<int>& nums){
        vector<int> dp(nums.size()+1,0);

        dp[nums.size()-1]=1;

        for(int index=nums.size()-2;index>=0;index--){
                
            bool ans=false;
            for(int i=index+1;i<=index+nums[index];i++){

                if(dp[i]){
                    ans= true;
                    break;
                }
            }

            dp[index]=ans;
        }

        return dp[0];

    }


public:
    bool canJump(vector<int>& nums) {
        
        if(nums.size()==1){
            return true;
        }

        //return solve(nums,0);

        // vector<int> dp(nums.size()+1,-1);
        // return dpSolve(nums,0,dp);


        return tabuSolve(nums);
    }
};