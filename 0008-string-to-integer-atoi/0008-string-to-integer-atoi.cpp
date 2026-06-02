class Solution {
public:
    int myAtoi(string s) {
        

        int i=0;

        //white spaces remove
        while(s[i]==' '){
            i++;
        }

        bool minus=false;
        if(s[i]=='-'){
            minus=true;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }

        while(s[i]=='0'){
            i++;
        }

        long long ans=0; 


        while(i<s.length() && '0'<=s[i] && s[i]<='9'){
            int digit=s[i]-'0';
            ans=(ans*10)+digit;

            if(ans>INT_MAX){
            
                if(minus){
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }
               
            }
            
            i++;
        }

        if(minus){
            ans=-ans;
        }


        return ans==0?0:ans;
    }
};