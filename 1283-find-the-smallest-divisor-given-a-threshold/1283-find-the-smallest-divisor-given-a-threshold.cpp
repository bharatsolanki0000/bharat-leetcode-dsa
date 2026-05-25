class Solution {

    bool check(vector<int>& nums, int threshold, int divisor){

        long long sum=0;

        for(int i=0;i<nums.size();i++){

            sum+=ceil((double)nums[i]/divisor);

            if(sum>threshold){
                break;
            }
        }

        return sum<=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int start=1;
        int end=*max_element(nums.begin(), nums.end());
        int ans=-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(check(nums, threshold,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return ans;
    }
};