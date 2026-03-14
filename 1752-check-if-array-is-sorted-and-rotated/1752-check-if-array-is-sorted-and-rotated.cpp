class Solution {
public:
    bool check(vector<int>& nums) {

        if(nums.size()==1){
            return true;
        }
        
       

        bool pivot=false;

        for(int i=0;i<nums.size()-1;i++){
            
            if(pivot && nums[i]>nums[i+1]){
                return false;
            }

            if(nums[i]>nums[i+1]){
                pivot=true;
            }
            
        }

        if(pivot && nums[0]<nums[nums.size()-1]){
            return false;
        }
        return true;
    }
};