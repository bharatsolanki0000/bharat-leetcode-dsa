class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

         int rowSize=matrix.size();
         int colSize=matrix[0].size();

         if(rowSize==colSize && rowSize==1){
            return matrix[0][0]==target;
         }

         int row=rowSize-1;
         int col=0;
         while( row>=0 && col<colSize){


            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                row--;
            }
            else{
                col++;
            }
         }

         return false;
    }
};