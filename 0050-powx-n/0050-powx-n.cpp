class Solution {

    double solve(double x, long n){

        if(n==0){
            return 1;
        }

        if(n==1){
            return x;
        }

        if(n<0){
            return 1/solve(x,-n);
        }
        else if(n%2==0){
            return solve(x*x,n/2);
        }
        else{
            return solve(x,n-1)*x;
        }
    }
public:
    double myPow(double x, int n) {
        return solve(x,n);
    }
};