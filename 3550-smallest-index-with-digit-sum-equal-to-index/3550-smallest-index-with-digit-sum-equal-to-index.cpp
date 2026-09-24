class Solution {

    int getSum(int num){

        int sum=0;

        while(num>0){
            int last=num%10;
            sum+=last;
            num/=10;
        }

        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {

        for(int i=0;i<nums.size();i++){

            int tempSum=getSum(nums[i]);
            if(tempSum==i){
                return i;
            }
        }

        return -1;
    }
};