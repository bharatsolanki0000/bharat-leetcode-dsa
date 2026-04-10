class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        if(nums.size()<3){
            return -1;
        }

        int ans =INT_MAX;

        unordered_map<int,vector<int>> mp;

        for(int i=0;i<nums.size();i++){

            mp[nums[i]].push_back(i);

            auto &v=mp[nums[i]];
            int size=v.size();

            if(size>=3){
                ans=min(ans, 2*(v[size-1] -v[size-3]));
            }

        }  

        return ans==INT_MAX?-1:ans;


    }
};