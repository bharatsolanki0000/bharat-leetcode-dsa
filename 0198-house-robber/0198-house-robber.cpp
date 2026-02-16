class Solution {

    int solve(vector<int>& nums, int index, vector<int>&dp){

        if(index>=nums.size()){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }


        int thisHouse=nums[index]+solve(nums, index+2,dp);

        int nextHouse=solve(nums,index+1,dp);

        return dp[index]=max(thisHouse, nextHouse);
    }
public:
    int rob(vector<int>& nums) {

        vector<int> dp(nums.size()+1,-1);
        return solve(nums, 0,dp);
    }
};