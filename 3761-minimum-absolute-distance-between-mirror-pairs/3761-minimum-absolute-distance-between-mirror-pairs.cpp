class Solution {

    int reverse(int element){
        int temp=0;
        while(element>0){
            int last=element%10;
             temp=(temp*10)+last;
             element/=10;
        }

        return temp; 
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        
        if(nums.size()==1){
            return -1;
        }


        unordered_map<int,int> next;
        next[reverse(nums[0])]=0;


    

        int ans=INT_MAX;

        for(int i=1;i<nums.size();i++){
            int element=nums[i];

            if(next.count(element)){
                ans=min(ans, i-next[element]);
            }

            next[reverse(nums[i])]=i;

        }

        if (ans==INT_MAX) return -1;

        return ans;

    }
};