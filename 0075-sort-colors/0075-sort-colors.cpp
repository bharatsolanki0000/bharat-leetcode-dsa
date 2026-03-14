class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int one=0;
        int two=nums.size()-1;
        int zero=0;

        while(one<=two){

            if(nums[one]==0){
                swap(nums[one],nums[zero]);
                zero++;
                one++;
            }
            else if(nums[one]==2){
                swap(nums[two],nums[one]);
                two--;
            }
            else if(nums[one]==1){
                one++;
            }
        }
    }
};