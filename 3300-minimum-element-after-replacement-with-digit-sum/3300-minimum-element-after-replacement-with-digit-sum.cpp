class Solution {

    int getSum(int n){

        int sum=0;

        while(n>0){
            int last=n%10;
            sum+=last;
            n=n/10;
        }

        return sum;

    }
public:
    int minElement(vector<int>& nums) {
        
        int ans=INT_MAX;

        for(int i=0;i<nums.size();i++){

            int temp=getSum(nums[i]);
            
            ans=min(ans, temp);

        }
        return ans;
    }
};