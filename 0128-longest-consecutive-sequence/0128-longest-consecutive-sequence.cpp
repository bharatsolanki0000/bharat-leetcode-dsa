class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> container;
        for(int i=0;i<nums.size();i++){
            container.insert(nums[i]);
        }

        int count=1;
        int maxi=0;

        while(!container.empty()){
            auto first=*container.begin();
            container.erase(container.begin());

            auto second=INT_MIN;
            if(!container.empty()){
                second=*container.begin();
            }

            if(first+1==second){
                count++;
            }
            else{
                count=1;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};