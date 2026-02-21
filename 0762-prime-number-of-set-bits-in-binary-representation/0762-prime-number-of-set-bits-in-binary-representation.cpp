class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        set<int> isPrime={2,3,5,7,11,13,17,19};
        int ans=0;
        for(int i=left;i<=right;i++){
           
           int count=0;
           int num=i;

           while(num>0){
                count+=num&1;
                num>>=1;
           }

            if(isPrime.find(count)!=isPrime.end()){
                ans++;
            }
        }

        return ans;
    }
};