class Solution {

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int rowSize=grid.size();
        int colSize=grid[0].size();
        long long totalSum=0;

        vector<long long> rowSum(rowSize,0);
        vector<long long> colSum(colSize,0);

        for(int i=0;i<rowSize;i++){
            int tempRowSum=0;
            for(int j=0;j<colSize;j++){
                totalSum+=grid[i][j];
                rowSum[i]+=grid[i][j];
                colSum[j]+=grid[i][j];
            }
           
        }

        if(totalSum %2!=0){
            return false;
        }

        long long tempSum=0;

        //vertical cut we use colSum;
        for(int i=0;i<colSum.size()-1;i++){ 
            tempSum+=colSum[i];

            if(totalSum-tempSum==tempSum){
                return true;
            }
        }


        tempSum=0;
        for(int i=0;i<rowSum.size()-1;i++){ 
            tempSum+=rowSum[i];

            if(totalSum-tempSum==tempSum){
                return true;
            }
        }
        return false;



    }
};