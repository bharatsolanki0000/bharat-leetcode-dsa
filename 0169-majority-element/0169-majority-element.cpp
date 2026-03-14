class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int first=nums[0];

        for(int i=0;i<nums.size();i++){


            if(nums[i]==first){
                count++;
            }
            else{
                count--;
            }

            if(count==0){
                first=nums[i];
                count++;
            }

        }

        return first;
    }
};