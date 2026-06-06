class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        vector<int> leftSum(nums.size()), rightSum(nums.size());

        int sum=0;
        for(int i=0;i<nums.size();i++){
            leftSum[i]=sum;
            sum+=nums[i];
        }

        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            rightSum[i]=sum;
            sum+=nums[i];
        }

        vector<int> ans(nums.size());

        for(int i=0;i<nums.size();i++){
            ans[i]=abs(leftSum[i]-rightSum[i]);
        }

        return ans;

    }
};