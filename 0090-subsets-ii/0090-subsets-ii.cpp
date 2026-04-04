class Solution {
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int>& temp, int index ){
            if(index==nums.size()){
                ans.push_back(temp);
                return ;
            }

            int i=index+1;

            while(i<nums.size() && nums[i]==nums[i-1]){
                i++;
            }


            //take
            temp.push_back(nums[index]);
            solve(nums, ans,temp,index+1);
            temp.pop_back();


            //not take
            solve(nums, ans, temp, i);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
         vector<int>temp;
         vector<vector<int>> ans;
         solve(nums, ans, temp, 0);
         //sort(ans.begin(), ans.end());
         return ans;
    }
};