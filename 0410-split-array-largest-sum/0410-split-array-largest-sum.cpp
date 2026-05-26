class Solution {

    bool check(vector<int>& nums, int k, int maxSum){

        int part=1;
        int tempSum=0;

        for(int i=0;i<nums.size();i++){

            if(tempSum+nums[i]<=maxSum){
                tempSum+=nums[i];
            }
            else{
                part++;
                tempSum=nums[i];
            }
        }

        return part<=k;
    }

    // int linear(vector<int>& nums, int k){

    // }

    int binarySearch(vector<int>& nums, int k){

        int start=*max_element(nums.begin(), nums.end());

        int end;
        for(auto temp:nums){
            end+=temp;
        }
        int ans=0;

        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(check(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return ans;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        
        return binarySearch(nums,k);

    }
};