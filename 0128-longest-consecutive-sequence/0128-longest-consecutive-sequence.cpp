class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0){
            return 0;
        }

        if(nums.size()==1){
            return 1;
        }
        
        unordered_set<int> temp;

        for(auto ele: nums){
            temp.insert(ele);
        }

        int ans=1;
        for(auto element: temp){

            int count=1;
            int prevElement=element-1;
            if(!temp.count(prevElement)){
                
                while(temp.count(element+1)){
                    count++;
                    element++;
                }

                ans=max(ans,count);
            }
        }
        
        return ans;
    }
};