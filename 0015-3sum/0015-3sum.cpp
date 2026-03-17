class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int k=0;k<=nums.size()-1;k++){

            int element=nums[k];
            if(k>0 && element ==nums[k-1]){
                continue;
            }

            int i=k+1;
            int j=nums.size()-1;

            while(i<j){
                int sum=element+nums[i]+nums[j];
                if(sum==0){
                    ans.push_back({element, nums[i], nums[j]});
                    i++;
                    j--;

                    while(i<j && nums[i]==nums[i-1]){
                        i++;
                    }

                    while(i<j && nums[j]==nums[j+1]){
                        j--;
                    }
                }
                else if(sum<0){
                    i++;
                }
                else{
                    j--;
                }
               



            }
           
            
        }
        return ans;
    }
};