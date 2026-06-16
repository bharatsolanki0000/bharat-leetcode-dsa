class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int open=0;
        int close=0;

        for(auto ch:s){
            if(ch==')'){

                if(open>0){
                    open--;
                }
                else{
                    close++;
                }
            }
            else{
                open++;
            }
        }
        return open+close;
        
    }
};