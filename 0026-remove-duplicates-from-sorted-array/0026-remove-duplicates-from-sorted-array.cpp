class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size()==1){
            return 1;
        }

        int index=0;
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[index]!=nums[i]){
                count++;
                nums[++index]=nums[i];
            }
        }
        return count;

    }
};