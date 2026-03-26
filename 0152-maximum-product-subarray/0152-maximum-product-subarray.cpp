class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if(nums.size()==1){
            return nums[0];
        }
        

        long long maxProduct=INT_MIN;

        long long tempProduct=1;
        for(int i=0;i<nums.size();i++){

            if(nums[i]==0){
              
                maxProduct=max(maxProduct,(long long)0);
                tempProduct=1;
                continue;
            }

            tempProduct*=nums[i];
            maxProduct=max(maxProduct,tempProduct);

        }
        tempProduct=1;
        for(int i=nums.size()-1;i>=0;i--){

             if(nums[i]==0){
                maxProduct=max(maxProduct,(long long)0);
                tempProduct=1;
                continue;
            }

            tempProduct*=nums[i];
            maxProduct=max(maxProduct,tempProduct);

        }

        return maxProduct;


    }
};