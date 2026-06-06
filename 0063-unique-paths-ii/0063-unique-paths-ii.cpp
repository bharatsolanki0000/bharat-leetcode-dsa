class Solution {

    int solve(vector<vector<int>>& nums, int i, int j){

        int rowSize=nums.size();
        int colSize=nums[0].size();

        if(i>=rowSize || j>=colSize || nums[i][j]!=0){
            return INT_MIN;
        }

        if(i==rowSize-1 && j==colSize-1){
            return 1;
        }

        int ans=0;

        int right=solve(nums,i,j+1);

        if(right!=INT_MIN){
            ans+=right;
        }

        int down=solve(nums, i+1,j);

        if(down!=INT_MIN){
            ans+=down;
        }

        return ans;

    }

    int dpSolve(vector<vector<int>>& nums, int i, int j,vector<vector<int>> &dp){

        int rowSize=nums.size();
        int colSize=nums[0].size();

        if(i>=rowSize || j>=colSize || nums[i][j]!=0){
            return INT_MIN;
        }

        if(i==rowSize-1 && j==colSize-1){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;

        int right=dpSolve(nums,i,j+1,dp);

        if(right!=INT_MIN){
            ans+=right;
        }

        int down=dpSolve(nums, i+1,j,dp);

        if(down!=INT_MIN){
            ans+=down;
        }

        return dp[i][j]=ans;

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int rowSize=obstacleGrid.size();
        int colSize=obstacleGrid[0].size();
        // int result=solve(obstacleGrid, 0,0);

        // return result==INT_MIN?0:result;


        vector<vector<int>> dp(rowSize+1, vector<int> (colSize+1, -1));
        int result=dpSolve(obstacleGrid, 0,0,dp);
        return result==INT_MIN?0:result;
    }
};