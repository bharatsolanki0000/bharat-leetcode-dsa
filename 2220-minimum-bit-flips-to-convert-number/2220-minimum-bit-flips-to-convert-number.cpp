class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int ans=0;
        int num= (start^goal);

        while(num>0){
            ans+=(num&1);
            num>>=1;
        }
        return ans;
    }
};