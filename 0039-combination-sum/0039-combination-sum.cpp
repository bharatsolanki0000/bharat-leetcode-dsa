class Solution {

    void solve(vector<int>& nums, int target, vector<int> &temp, vector<vector<int>> &ans,int index){
        
        
        if(target==0){
            ans.push_back(temp);
            return ;
        }

        if(index==nums.size()){
            return ;
        }
        
        for(int i=index;i<nums.size();i++){
            if(nums[i]<=target){
                temp.push_back(nums[i]);
                solve(nums, target-nums[i],temp,ans,i);
                temp.pop_back();
            }
        }

        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        solve(candidates, target,temp, ans,0);
        return ans;
    }
};