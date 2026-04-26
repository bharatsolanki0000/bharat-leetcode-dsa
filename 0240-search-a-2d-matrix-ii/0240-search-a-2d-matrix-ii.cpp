class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int rowSize=matrix.size();
        int colSize=matrix[0].size();

        if(rowSize==colSize && rowSize==1){
            return matrix[0][0]==target;
        }

        int row=0;
        int col=colSize-1;


        while(row<rowSize && col>=0){


            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col] < target){
                row++;
            }
            else{
                col--;
            }
        }

        return false;



    }
};