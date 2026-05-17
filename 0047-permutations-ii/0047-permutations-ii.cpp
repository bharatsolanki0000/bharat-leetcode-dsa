class Solution {

    void solve(vector<int>&nums, vector<vector<int>> & ans, int index){

        if(index==nums.size()){
            ans.push_back(nums);
            return; 
        }

        unordered_map<int,int> mp;

        for(int i=index;i<nums.size();i++){

        if(mp.count(nums[i])){
            continue;
        }

            mp[nums[i]]++;
            swap(nums[i], nums[index]);
            solve(nums, ans ,index+1);
            swap(nums[i], nums[index]);
            
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums, ans, 0);
        return ans;
    }
};