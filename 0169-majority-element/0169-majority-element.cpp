class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> votes;

        float exceedVotes=nums.size()/2;
        for(int i=0;i<nums.size();i++){
            votes[nums[i]]++;
            
            if(votes[nums[i]]>exceedVotes){
                return nums[i];
            }
        }
        return -1;
    }
};