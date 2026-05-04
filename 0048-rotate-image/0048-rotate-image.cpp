class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //traspose the matrix
       
        int rowSize=matrix.size();
        int colSize=matrix[0].size();

        for(int row=0;row<rowSize;row++){
            for(int col=row;col<colSize;col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        int firstCol=0;
        int lastCol=colSize-1;

        while(firstCol<lastCol){

            for(int row=0;row<rowSize;row++){
                swap(matrix[row][firstCol], matrix[row][lastCol]);
            }
            firstCol++;
            lastCol--;
        }
    }
};