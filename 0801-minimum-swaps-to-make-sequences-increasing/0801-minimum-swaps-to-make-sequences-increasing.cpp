class Solution {
    int solve(vector<int>& nums1, vector<int>& nums2, int index ,bool isSwapped){
        int size=nums1.size();
        if(index==size){
            return 0;
        }

        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        //check
        if(isSwapped){
            swap(prev1, prev2);
        }

        int swapped=INT_MAX;
        int notSwapped=INT_MAX;
        //no swap
        if(nums1[index]>prev1 && nums2[index]>prev2){
            notSwapped= solve(nums1,nums2,index+1, 0);

        }
      

        if(nums1[index]>prev2 && nums2[index]>prev1){
            swapped=1+solve(nums1, nums2, index+1,1);
        }

        return min(swapped, notSwapped);

    }

     int dpSolve(vector<int>& nums1, vector<int>& nums2, int index ,int isSwapped, vector<vector<int>> &dp){
        int size=nums1.size();

        if(index==size){
            return 0;
        }

        if(dp[index][isSwapped]!=-1){
            return dp[index][isSwapped];
        }

        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        //check
        if(isSwapped){
            swap(prev1, prev2);
        }

        int swapped=INT_MAX;
        int notSwapped=INT_MAX;
        //no swap
        if(nums1[index]>prev1 && nums2[index]>prev2){
            notSwapped= dpSolve(nums1,nums2,index+1, 0,dp);

        }
      

        if(nums1[index]>prev2 && nums2[index]>prev1){
            swapped=1+dpSolve(nums1, nums2, index+1,1,dp);
        }

        return dp[index][isSwapped]= min(swapped, notSwapped);

    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

       // return solve(nums1, nums2, 1,0);

       //rec+memo
       vector<vector<int>> dp(nums1.size(), vector<int> (2,-1));
       return dpSolve(nums1, nums2,1,0,dp);
    }
};