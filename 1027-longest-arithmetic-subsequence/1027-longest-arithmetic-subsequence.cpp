class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {

        int maxi=2;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int diff=nums[j]-nums[i];
                int ans=2;
                int last=nums[j];
                for(int k=j+1;k<nums.size();k++){
                    if(nums[k]-last==diff){
                        ans++;
                        last=nums[k];
                    }
                }
                maxi=max(maxi,ans);
            }
        }
        return maxi;
    }
};