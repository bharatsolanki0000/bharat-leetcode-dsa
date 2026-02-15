class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //transpose
        int rowSize=matrix.size();
        int colSize=matrix[0].size();

        for(int i=0;i<rowSize;i++){
            for(int j=i;j<colSize;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }


        //reverse cols or swap cols last with first
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