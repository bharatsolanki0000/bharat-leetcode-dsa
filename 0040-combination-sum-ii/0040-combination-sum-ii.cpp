class Solution {

    void solve(vector<int>&nums, int target,vector<vector<int>>&ans, vector<int>&temp, int index){

        if(target==0){
            ans.push_back(temp);
            return; 
        }

        if(index==nums.size()){
            return ;
        }


        for(int i=index;i<nums.size();i++){

            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            
            if(nums[i]<=target){
                temp.push_back(nums[i]);
                solve(nums,target-nums[i], ans, temp,i+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
          vector<int>temp; 
          sort(candidates.begin(), candidates.end());
          solve(candidates,target,ans,temp,0);
          return ans;
    }
};