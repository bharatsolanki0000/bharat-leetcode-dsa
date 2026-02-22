class Solution {
public:
    int binaryGap(int n) {
        
        int ans=0;
        int count=-1;

        while(n>0){
            
            int bit=n&1;
            if(bit==1){
                ans=max(ans, count);
                count=0;
            }
            else if(count==-1){
                n>>=1;
                continue;
            }
            n>>=1;
            count++;
            
        }
        return ans;

    }
};