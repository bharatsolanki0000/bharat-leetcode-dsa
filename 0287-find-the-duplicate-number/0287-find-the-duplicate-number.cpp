class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
        int low=nums[0];
        int fast=nums[0];
        int size=nums.size();
        do {
            low=nums[low];
            fast=nums[nums[fast]];
        } 
        while(low!=fast);

        fast=nums[0];
        while(fast!=low){
             low=nums[low];
            fast=nums[fast];
        }

        return low;
    }
};