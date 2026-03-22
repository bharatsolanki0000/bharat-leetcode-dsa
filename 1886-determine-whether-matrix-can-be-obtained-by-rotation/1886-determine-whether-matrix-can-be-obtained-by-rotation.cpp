class Solution {

    void transpose(vector<vector<int>>& mat){

        int size=mat.size();
        for(int i=0;i<size;i++){
            for(int j=i;j<size;j++){

                swap(mat[i][j], mat[j][i]);
            }
        }
    }

    void rev (vector<vector<int>>& mat){
        for(int i=0;i<mat.size();i++){
            reverse(mat[i].begin(), mat[i].end());
        }

    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        

        for(int i=0;i<4;i++){

            //rotate 90
            transpose(mat);
            rev(mat);

            //check
            if(mat==target){
                return true;
            }



        }

        return false;


    }
};