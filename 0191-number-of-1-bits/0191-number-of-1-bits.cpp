class Solution {

    int logn(int n){

        //checking every unit bit (lsb) or the rightest bit 
        //if and of lsb with 1 is 1 means it is 1 so ans++

        int i=0;
        int ans=0;

        while(n>0){

            ans+=((n&1)==1);
            n=n>>1;


        }

        return ans;
    }

    int ok(int n){
        //chekcing only the 1 bit 
        //it removes the rightmost set bit . so times the loop runs = set bits count

        int ans=0;
        while(n){
            n= (n&(n-1));
            ans++;
        }

        return ans;


    }
public:
    int hammingWeight(int n) {
        //log(n) tc
        //return logn(n);


        //O(k) tc
        return ok(n);
    }   
};