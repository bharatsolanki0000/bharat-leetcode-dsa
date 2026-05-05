class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        if(nums.size()==1){

            if(nums[0]==k){
                return 1;
            }
            return 0;
        }
        
        vector<int> prefix(nums.size(), 0);
        prefix[0]=nums[0];

        int ans=0;


        for(int i=1;i<nums.size();i++){
            prefix[i]=nums[i]+prefix[i-1];
        }

        unordered_map<int,int> mp;
        mp[0]=1;

        for(int i=0;i<prefix.size();i++){

            int element=prefix[i]-k;

            if(mp.count(element)){
                ans+=mp[element];
            }
            mp[prefix[i]]++;
           
        }
        return ans;
    }
};