class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;


        for(int i=0;i<nums.size();i++){

            int element=target-nums[i];
            if(mp.count(element)){
                return {i,mp[element]};
            }

            mp[nums[i]]=i;
        }
        return {};
    }
};