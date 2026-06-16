class Solution {
public:
    string processStr(string s) {
        
        string ans="";
        
        for(auto ch:s){
            if(ch=='#'){
                if(!ans.empty()){
                    ans=ans+ans;
                }
            }
            else if(ch=='*'){
                if(!ans.empty()){
                    ans.pop_back();
                }
            }
            else if(ch=='%'){
                reverse(ans.begin(), ans.end());
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};