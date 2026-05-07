class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        
        int size=nums.size();
        //min suffix or next smaller


        vector<int> minSuffix(size);
        minSuffix[size-1]=nums[size-1];

        for(int i=size-2;i>=0;i--){
            minSuffix[i]=min(nums[i], minSuffix[i+1]);
        }

        //max prefix or prev greater

        vector<int> maxPrefix(size);
        maxPrefix[0]=nums[0];

        for(int i=1;i<size;i++){
            maxPrefix[i]=max(nums[i], maxPrefix[i-1]);
        }

        vector<int>ans(size, 0);

        ans[size-1]=maxPrefix[size-1];
        for(int i=size-2;i>=0;i--){

            if(maxPrefix[i]<=minSuffix[i+1]){
                ans[i]=maxPrefix[i];
            }
            else{
                ans[i]=ans[i+1];
            }
        }


        
        return ans;

    }
};