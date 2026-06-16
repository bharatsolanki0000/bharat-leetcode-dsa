class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int open=0;
        int ans=0;

        for(auto ch:s){
            if(ch==')'){

                if(open>0){
                    open--;
                }
                else{
                    ans++;
                }
            }
            else{
                open++;
            }
        }
        return abs(open)+ans;
        
    }
};