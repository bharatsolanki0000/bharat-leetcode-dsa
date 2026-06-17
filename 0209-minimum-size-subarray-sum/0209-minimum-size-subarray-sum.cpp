class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int ansMinLen=INT_MAX;

        int i=0;
        int j=0;
        int sum=0;

        while(j<nums.size()){
            sum+=nums[j];

            while(sum>=target){

                if(j-i+1 <ansMinLen){
                    ansMinLen=j-i+1;
                }

                sum-=nums[i];
                i++;
            }

            j++;
        }

        return ansMinLen==INT_MAX?0:ansMinLen;

        
    }
};