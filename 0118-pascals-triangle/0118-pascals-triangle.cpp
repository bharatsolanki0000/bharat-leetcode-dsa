class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1){
            return {{1}};
        }

        vector<vector<int>> ans;
        ans.push_back({1});
        
        for(int i=2;i<=numRows;i++){
            vector<int> temp(i,1);

            vector<int> old=ans.back();
            for(int j=1;j<temp.size()-1;j++){
                temp[j]=old[j-1]+old[j];
            }
            ans.push_back(temp);
        }
        return ans;


    }
};