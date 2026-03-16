class Solution {

    void setZeros(int row, int col, vector<vector<int>>&matrix){

        int rowSize=matrix.size();
        int colSize=matrix[0].size();

        for(int j=0;j<colSize;j++){
            matrix[row][j]=0;
        }

        for(int i=0;i<rowSize;i++){
            matrix[i][col]=0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rowSize=matrix.size();
        int colSize=matrix[0].size();

        vector<pair<int,int>> containsZero;

        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(matrix[i][j]==0){
                    containsZero.push_back({i,j});
                }
            }
        }

        if(containsZero.size()==0){
            return;
        }

        for(auto indexes : containsZero){
            int row=indexes.first;
            int col=indexes.second;

            setZeros(row,col,matrix);
        }
    }
};