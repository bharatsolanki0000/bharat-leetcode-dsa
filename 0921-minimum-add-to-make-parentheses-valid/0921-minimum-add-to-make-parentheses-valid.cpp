class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int ans=0;

        for(auto ch:s){
            if(ch=='('){
                open++;
            }
            else if(open){
                open--;
            }
            else{
                ans++;
            }
        }

        return ans+open;
    }
};