class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> suffix(nums.size(),0);

        suffix[nums.size()-1]=nums[nums.size()-1];

        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }

        int prefix=1;

        for(int i=0;i<nums.size();i++){
            
            if(i==nums.size()-1){
                suffix[i]=prefix;
            }
            else{
                suffix[i]=suffix[i+1]*prefix;
            }
            

            prefix*=nums[i];
        }
        
        return suffix;
    }
};