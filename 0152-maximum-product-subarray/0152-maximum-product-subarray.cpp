class Solution {
public:
    int maxProduct(vector<int>& nums) {
        

        long long prefix=1;
        long long suffix=1;
        int size=nums.size();
        long long maxProduct=INT_MIN;

        for(int i=0;i<nums.size();i++){

            if(prefix==0){
                prefix=1;
            }

            if(suffix==0){
                suffix=1;
            }

            prefix*=nums[i];
            suffix*=nums[size-i-1];

            maxProduct=max(maxProduct, max(prefix,suffix));
        }

        return maxProduct;
    }
};