class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
  
        vector<int> nums;
        int rowSize=grid.size();
        int colSize=grid[0].size();
       
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());


        int mid=nums.size()/2;
        int ans=0;
        int target=nums[mid];
        for(int i=0;i<nums.size();i++){

                int temp=abs(target-nums[i]);

                if(temp%x!=0){
                    return -1;
                }

                ans+=temp/x;
            
        }

        return ans;

   }
};