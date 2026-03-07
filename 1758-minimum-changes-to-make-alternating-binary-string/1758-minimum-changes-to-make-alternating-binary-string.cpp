class Solution {
public:
    int minOperations(string s) {
        
        int one=s.length();
        int zero=s.length();

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

        int first=0;
        int second=0;

        for(int i=0;i<s.length();i++){
            if(s[i]!=startOne[i]){
                first++;
            }

            if(s[i]!=startZero[i]){
                second++;
            }
        }

        return min(first,second);
    }
};