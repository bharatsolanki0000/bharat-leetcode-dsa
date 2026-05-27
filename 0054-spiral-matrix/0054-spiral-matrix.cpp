class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        

        vector<int> ans;
        int rowSize=matrix.size();
        int colSize=matrix[0].size();

        int total=rowSize*colSize;
        int count=0;
        int startRow=0;
        int startCol=0;
        int endRow=rowSize-1;
        int endCol=colSize-1;

        while(count<total){
            
            for(int col=startCol;count<total && col<=endCol;col++){
                count++;
                ans.push_back(matrix[startRow][col]);
            }

            startRow++;


            for(int row=startRow;count<total && row<=endRow;row++){
                count++;
                ans.push_back(matrix[row][endCol]);
            }

            endCol--;



            for(int col=endCol;count<total && col>=startCol;col--){
                count++;
                ans.push_back(matrix[endRow][col]);
            }



            
            endRow--;

            for(int row=endRow;count<total && row>=startRow;row--){
                count++;
                ans.push_back(matrix[row][startCol]);
            }

            startCol++;
            
        }
        return ans;

    }
};


