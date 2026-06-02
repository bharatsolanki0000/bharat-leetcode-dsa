class Solution {
public:
    int maxDepth(string s) {

        int maxi=0;
        int open=0;
        
        for(int i=0;i<s.length();i++){

            if(s[i]=='('){
                open++;

                maxi=max(maxi,open);
            }
            else if(s[i]==')'){
                open--;
            }
        }

        return maxi;
    }
};