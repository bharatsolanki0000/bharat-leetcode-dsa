class Solution {
public:
    int countPrimes(int n) {
        //sieve of eratosthenes

        if(n==0 || n==1){
            return 0;
        }

        vector<bool> nums(n+1,true);
        int ans=0;

        for(int i=2;i<n;i++){

            if(nums[i]){
                ans++;

                for(int j=2*i;j<n;j+=i){
                    nums[j]=false;
                }
            }
        }
        return ans;



    }
};