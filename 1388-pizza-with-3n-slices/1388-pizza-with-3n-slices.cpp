class Solution {

    int solve(vector<int>& slices, int index, int size, int maxSlices){
        
        if(index>=size || maxSlices==0){
            return 0;
        }

        int takeThis=slices[index]+solve(slices, index+2, size, maxSlices-1);

        int takeNext=solve(slices,index+1, size, maxSlices);

        return max(takeThis, takeNext);
        
    }

    int dpSolve(vector<int>& slices, int index, int size, int maxSlices, vector<vector<int>> &dp){
          
        if(index>=size || maxSlices==0){
            return 0;
        }

        if(dp[index][maxSlices]!=-1){ 
            return dp[index][maxSlices];
        }


        int takeThis=slices[index]+dpSolve(slices, index+2, size, maxSlices-1,dp);

        int takeNext=dpSolve(slices,index+1, size, maxSlices,dp);

        return dp[index][maxSlices]=max(takeThis, takeNext);
        
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        
        int size=slices.size();
        int maxSlices=size/3;
        //return max(solve(slices, 0, size-1, maxSlices), solve(slices, 1, size, maxSlices));

        //rec +memo
        vector<vector<int>> dp1(size+1, vector<int> (maxSlices+1,-1)), dp2(size+1, vector<int> (maxSlices+1,-1));
        return max(dpSolve(slices, 0, size-1, maxSlices,dp1), dpSolve(slices, 1, size, maxSlices, dp2));

    }
};