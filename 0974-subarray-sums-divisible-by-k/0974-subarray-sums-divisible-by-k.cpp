class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        mp[0]=1;


        int ans=0;
        int prefixSum=0;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];

            int temp=((prefixSum%k)+k)%k;

            ans+=mp[temp];
            mp[temp]++;

        }

        return ans;
    }
};