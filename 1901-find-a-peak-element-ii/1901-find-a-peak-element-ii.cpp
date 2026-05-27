class Solution {

    int findPeakRowIndex(vector<vector<int>>& mat, int col){

        int index=-1;
        int maxi=-1;
        for(int i=0;i<mat.size();i++){
            if(maxi<mat[i][col]){
                maxi=mat[i][col];
                index=i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int rowSize=mat.size();
        int colSize=mat[0].size();

        int start=0;
        int end=colSize-1;

        while(start<=end){

            int peakColIndex=start+(end-start)/2;

            int peakRowIndex=findPeakRowIndex(mat,peakColIndex);

            if(peakRowIndex==-1){
                continue;
            }

            int left=peakColIndex-1>=0? mat[peakRowIndex][peakColIndex-1]:INT_MIN;
            int right=peakColIndex+1<colSize? mat[peakRowIndex][peakColIndex+1]:INT_MIN;

            if(left<mat[peakRowIndex][peakColIndex] && right<mat[peakRowIndex][peakColIndex]){
                return {peakRowIndex, peakColIndex};
            }
            else if(left>mat[peakRowIndex][peakColIndex]){
                end=peakColIndex-1;
            }
            else{
                start=peakColIndex+1;
            }
        }
        return {-1,-1};
    }
};