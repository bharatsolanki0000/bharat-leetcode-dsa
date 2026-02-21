class Solution {

    int solve(vector<int>& nums){
       
        int maxi=2;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int diff=nums[j]-nums[i];
                maxi=max(maxi,2+solveHelper(i,diff,nums));
            }
        }
        return maxi;
    }

    int solveHelper(int index, int diff, vector<int>&nums){
         if(index<0){
            return 0;
        }
        int ans=0;
        for(int k=index-1;k>=0;k--){
            if(nums[index]-nums[k]==diff){
                ans=max(ans, 1+solveHelper(k,diff, nums));
            }
        }
        return ans;
    }

    int dpSolve(vector<int>& nums){
        vector<unordered_map<int,int>> dp(nums.size());
       
        int maxi=2;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int diff=nums[j]-nums[i];
                maxi=max(maxi,2+dpSolveHelper(i,diff,nums,dp));
            }
        }
        return maxi;
    }
    int dpSolveHelper(int index, int diff, vector<int>&nums,
    vector<unordered_map<int,int>> &dp){
         if(index<0){
            return 0;
        }
        if(dp[index].count(diff)){
            return dp[index][diff];
        }
        int ans=0;
        for(int k=index-1;k>=0;k--){
            if(nums[index]-nums[k]==diff){
                ans=max(ans, 1+dpSolveHelper(k,diff, nums,dp));
            }
        }
        return dp[index][diff]=ans;
    }

public:
    int longestArithSeqLength(vector<int>& nums) {
        //return solve(nums);


        return dpSolve(nums);
    }
};