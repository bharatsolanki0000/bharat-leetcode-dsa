class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int i=0;
         int j=0;
         int count=0;
         int ans=0;

         while(j<nums.size()){

            if(nums[j]==0){
                count++;
            }

            while(count>k){
                ans=max(ans, j-i);

                if(nums[i]==0){
                    count--;
                }
                i++;
            }
            j++;
         }

         ans=max(ans, j-i);

         return ans;
    }
};