class Solution {

    bool solve(vector<int>&nums, int target, int index){
        
        if(target==0){
            return true;
        }
        if(index==nums.size() || target<0){
            return false;
        }

        //take
        bool take=solve(nums, target-nums[index], index+1);

        bool notTake=solve(nums, target, index+1);

        return take||notTake;
         

    }

     bool dpSolve(vector<int>&nums, int target, int index, vector<vector<int>> &dp){
        
        if(target==0){
            return true;
        }
        if(index==nums.size() || target<0){
            return false;
        }

        if(dp[index][target]!=-1){  
            return dp[index][target];
        }

        //take
        bool take=dpSolve(nums, target-nums[index], index+1, dp);

        bool notTake=dpSolve(nums, target, index+1,dp);

        dp[index][target]= take||notTake;
        return dp[index][target];

    }

public:
    bool canPartition(vector<int>& nums) {
        int target=0;

        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }

        //odd sum can't have 2 subsets
        if(target%2!=0){
            return false;
        }

        //rec
        //return solve(nums, target/2, 0);


        //rec +memo
        vector<vector<int>> dp(nums.size(), vector<int> ((target/2)+1, -1));
        return dpSolve(nums, target/2,0, dp);
       
        
    }
};