class Solution {
public:
    bool search(vector<int>& nums, int target) {
        

        int start=0;
        int size=nums.size();
        int end=size-1;

        if(nums[start]==target || nums[size-1]==target){
            return true;
        }


        while(start<=end){
            int mid=start+(end-start)/2;

            if(nums[mid]==target){
                return true;
            }
            //DUPLICATE ON BOTH ENDS  
            else if(nums[start]==nums[mid] && nums[mid]==nums[end]){
                start++;
                end--;
            }
            //left sorted
            else if(nums[start]<=nums[mid]){

                if(target>=nums[start] && target< nums[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }


            }
            else{
                //right sorted

                if(target>=nums[mid] && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }

        return false;
    }
};