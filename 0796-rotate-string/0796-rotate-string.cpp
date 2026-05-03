class Solution {

    bool check(int j, string &goal, string &s){

        if(s.length()-j<goal.length()){
            return false;
        }

        for(int i=0;i<goal.length();i++){
            if(s[j+i]!=goal[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool rotateString(string s, string goal) {  

        if(s.length()!=goal.length()){
            return false;
        }

        s=s+s;

        for(int i=0;i<s.length();i++){

            if(check(i,goal,s)){
                return true;
            }
            
        }
        return false;
        
    }
};