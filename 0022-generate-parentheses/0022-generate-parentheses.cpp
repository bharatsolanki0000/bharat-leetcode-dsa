class Solution {

    void solve(int &n, vector<string>&ans, int open ,int close, string temp){

        if(open==n && close==n){
            ans.push_back(temp);
        }

        if(open>n || close>n){
            return;
        }

        //oppen
        solve(n, ans, open+1, close, temp+'(');

        //close
        if(close<open){
            solve(n, ans, open, close+1, temp+')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(n,ans, 0,0,"");
        return ans;
    }
};