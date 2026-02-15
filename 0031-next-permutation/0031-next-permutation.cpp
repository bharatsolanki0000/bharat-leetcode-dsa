class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int golaIndex=-1;

        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                golaIndex=i-1;
                break;
            }
        }
        int swapIndex=golaIndex;
        if(golaIndex!=-1){
            for(int i=nums.size()-1;i>=golaIndex+1;i--){
                if(nums[i]>nums[golaIndex]){
                    swapIndex=i;
                    break;
                }
            }

            swap(nums[swapIndex], nums[golaIndex]);

        }
        reverse(nums.begin()+golaIndex+1, nums.end());
    }
};