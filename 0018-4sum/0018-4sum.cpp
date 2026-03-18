class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<=nums.size()-1;i++){
            
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int a=nums[i];

            for(int j=i+1;j<=nums.size()-1;j++){

                
            if(j>i+1 && nums[j]==nums[j-1]){
                continue;
            }
                 
                 int b=nums[j];
                 int cIndex=j+1;
                 int dIndex=nums.size()-1;

            while(cIndex < dIndex){
                int c=nums[cIndex];
                int d=nums[dIndex];

                long long sum=(long long)a+b+c+d;

                if(sum<target){
                    cIndex++;
                }
                else if(sum> target){
                    dIndex--;
                }
                else{
                    
                    vector<int> temp={a,b,c,d};
                    ans.push_back(temp);
                   

                    while(cIndex < dIndex && nums[cIndex]==nums[cIndex+1]){
                        cIndex++;
                    }

                    while(cIndex < dIndex && nums[dIndex]==nums[dIndex-1]){
                        dIndex--;
                    }

                    cIndex++;
                    dIndex--;

                }
            }

            }
        }

        return ans;
    }
};