class Solution {

    int solve(vector<int>& nums, int k){

        int i=0, j=0,count=0;
        int ans=0;
        unordered_map<int,int> mp;

        while(j<nums.size()){

            if(!mp.count(nums[j])){
                count++;
            }
            mp[nums[j]]++;

            while(count>k){

                mp[nums[i]]--;

                if(mp[nums[i]]==0){
                    count--;
                    mp.erase(nums[i]);
                }

                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //says exactuly so i use atmost(k)- atmost(k-1);
        return solve(nums, k)-solve(nums, k-1);
    }   
};