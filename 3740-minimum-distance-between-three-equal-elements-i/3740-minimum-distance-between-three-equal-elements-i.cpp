class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        if(nums.size()<3){
            return -1;
        }

        int ans=INT_MAX;

        for(int i=0;i<nums.size()-2;i++){

            for(int j=i+1;j<nums.size()-1;j++){

                for(int k=j+1;k<nums.size();k++){

                    if(nums[i]==nums[j] &&  nums[i]==nums[k]){
                        int first=abs(i-j);
                        int second=abs(j-k);
                        int third=abs(k-i);
                        ans=min(ans, first+second+third);
                    }

                }
            }
        } 

        return ans!=INT_MAX?ans:-1;


    }
};