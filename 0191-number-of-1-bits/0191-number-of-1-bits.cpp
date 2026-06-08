class Solution {

    int logn(int n){

        int i=0;
        int ans=0;

        while(n>0){

            ans+=((n&1)==1);
            n=n>>1;


        }

        return ans;
    }

    // int Ok(int n){

    // }
public:
    int hammingWeight(int n) {
        //log(n) tc
        return logn(n);


        //O(k) tc
        //return ok(n);
    }   
};