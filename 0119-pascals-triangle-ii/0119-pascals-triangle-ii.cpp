class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> old={1};


        while(rowIndex){

            vector<int> newRow(old.size()+1,1);

            for(int i=1;i<old.size();i++){
                newRow[i]=old[i-1]+old[i]; 
            }
            rowIndex--;
            old=newRow;
        }

        return old;
    }
};