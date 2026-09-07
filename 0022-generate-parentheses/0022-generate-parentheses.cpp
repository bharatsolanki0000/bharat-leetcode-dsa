class Solution {

    void solve(int n, int open , int close, vector<string>&ans, string temp){

        if(open>n || close>n){
            return ;
        }
        
        if(open==n && close==n){
            ans.push_back(temp);
            return;
        }

        //open 
        solve(n,open+1,close,ans, temp+'(');

        //close should small than open
        if(open>close){
            solve(n,open,close+1, ans, temp+')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;

        vector<string>ans;
        string temp="";

        solve(n,open,close,ans, temp);
        return ans;
    }
};