class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0){
            return 0;
        }

        if(nums.size()==1){
            return 1;
        }
        
        set<int> temp;

        for(auto ele: nums){
            temp.insert(ele);
        }


        
        int oldTop=*temp.begin();
        temp.erase(temp.begin());

        int count=1;
        int ans=1;

        while(!temp.empty()){

            int newTop=*temp.begin();
            temp.erase(temp.begin());

            if(oldTop+1==newTop){
                count++;

                ans=max(ans,count);
            }
            else{
                count=1;
            }

            oldTop=newTop;
        }
        return ans;
    }
};