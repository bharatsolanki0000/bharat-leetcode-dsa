class Solution {

    void solve( vector<int> &temp, vector<vector<int>> &ans,vector<int>& candidates, int target, int index){

            if(target==0){
                ans.push_back(temp);
                return ;
            }


            for(int i=index;i<candidates.size();i++){
                if(candidates[i]<=target){
                    temp.push_back(candidates[i]);
                    solve(temp, ans, candidates,target-candidates[i],  i);
                    temp.pop_back();
                }
            }   

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(temp,ans,candidates, target, 0);
        return ans;
    }
};