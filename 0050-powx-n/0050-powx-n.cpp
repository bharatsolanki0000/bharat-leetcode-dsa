class Solution {

    double solve(double x, long n){
        if(n==0){
            return 1;
        }

        if(n<0){
            return 1/solve(x,-n);
        }

        if(n%2==0){
            //even power
            return solve(x*x,n/2);
        }
        else{
            return x*solve(x,n-1);
        }
    }
public:
    double myPow(double x, int n) {
        return solve(x,n);
    }
};