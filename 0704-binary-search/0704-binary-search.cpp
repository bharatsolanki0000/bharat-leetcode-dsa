class Solution {

    int solve(vector<int>& nums, int &target, int start, int end){
        if(start>end){
            return -1;
        }

        int mid=start+(end-start)/2;

        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            return solve(nums, target, mid+1,end);
        }
        else{
            return solve(nums, target, start, mid-1);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return solve(nums,target,0,nums.size()-1);
    }
};