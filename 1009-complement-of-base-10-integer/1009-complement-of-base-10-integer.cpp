class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }

        if(n==1){
            return 0;
        }

        int num=0;
        int power=1;

        while(n>0){
            int bit=n%2;

            if(bit==0){
                //let it 1
                num=num+power;
            }
                //let it 0
                power*=2;
            

            n/=2;
        }

        return num;


    }
};