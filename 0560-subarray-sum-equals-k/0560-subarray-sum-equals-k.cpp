class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix=0;
        int ans=0;
        unordered_map<int,int> mp;
        mp[0]=1;

        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            int element=prefix-k;

            if(mp.count(element)){
                ans+=mp[element];
            }

            mp[prefix]++;
        }

        return ans;

    }
};