class Solution {
public:
    int bitwiseComplement(int n) {

        if(n==0){
            return 1;
        }

        if(n==1){
            return 0;
        }
        //convert num into binary

        string bits="";
        while(n>0){
            int bit=n%2;
            bits=char(bit+'0')+bits;
            n/=2;
        }
        
        int num=0;
        int power=1;
        for(int i=bits.length()-1;i>=0;i--){
            if(bits[i]=='0'){
                num+=power;
            }
            power*=2;
            
        }

        return num;
    }
};