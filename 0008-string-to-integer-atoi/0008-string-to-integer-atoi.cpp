class Solution {
public:
    int myAtoi(string s) {
        

        int i=0;
        long long ans=0;

        //remove white space from front
        while(i<s.length() && s[i]==' '){
            i++;
        }
 
        bool minus=false;

        if(s[i]=='-'){
            minus=true;
            i++;
        }
        else if(s[i]=='+'){
            minus=false;
            i++;
        }

        bool outRange=false;

        while(i<s.length() && (s[i]>='0' && s[i]<='9')){
            int digit=s[i]-'0';
            
            ans=(ans*10)+digit;
            
            if((ans<INT_MIN) || (ans>INT_MAX)){
                outRange=true;
                break;
            }
            i++;
        }

        if(outRange){
             if(minus){
                return INT_MIN;
            }
            else{
                return INT_MAX;
            }
        }

        if(minus){
            return -ans;
        }
        else{
            return ans;
        }

        


    }
};