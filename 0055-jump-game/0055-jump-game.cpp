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


public:
    bool canJump(vector<int>& nums) {
        
        if(nums.size()==1){
            return true;
        }

        //return solve(nums,0);

        vector<int> dp(nums.size()+1,-1);
        return dpSolve(nums,0,dp);
    }
};