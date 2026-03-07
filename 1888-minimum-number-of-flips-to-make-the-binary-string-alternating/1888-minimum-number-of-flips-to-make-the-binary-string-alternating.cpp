class Solution {
public:
    int minFlips(string s) {
        s=s+s;

        string startOne="";
        string startZero="";

        for(int i=0;i<s.length();i++){
            if(i%2==0){
                startOne.push_back('1');
                startZero.push_back('0');
            }
            else{
                startOne.push_back('0');
                startZero.push_back('1');
            }
        }

        int i=0;
        int j=0;
        int one=0;
        int zero=0;
        int ans=INT_MAX;

        while(j<s.length()){

            if(s[j]!=startOne[j]){
                one++;
            }
            if(s[j]!=startZero[j]){
                zero++;
            }

            

            if(j-i+1==s.length()/2){

                ans=min(ans,min(one,zero));

                if(startOne[i]!=s[i]){
                    one--;
                }
                if(startZero[i]!=s[i]){
                    zero--;
                }

                i++;
            }
            j++;
        }
        return ans;
    }
};