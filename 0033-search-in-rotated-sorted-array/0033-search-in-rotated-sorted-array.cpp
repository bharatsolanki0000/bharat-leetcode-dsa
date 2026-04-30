class Solution {

    int getPivot(vector<int>& nums){
        int start=0;
        int end=nums.size()-1;

        if(nums[0]<nums[end]){
            return 0;
        }

        while(start<end){

            int mid=start+(end-start)/2;

            if(nums[mid]>nums[end]){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }

        return start;


    }

    int findAns(vector<int> & nums, int target, int start, int end){

        while(start<=end){

            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]< target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot=getPivot(nums);
        int end=nums.size()-1;  

        int ans=-1;

        if(target<=nums[end] && target>=nums[pivot]){
            ans=findAns(nums, target, pivot, end);
        }
        else{
            ans= findAns(nums, target, 0, pivot-1);
        }

        return ans;
    }
};