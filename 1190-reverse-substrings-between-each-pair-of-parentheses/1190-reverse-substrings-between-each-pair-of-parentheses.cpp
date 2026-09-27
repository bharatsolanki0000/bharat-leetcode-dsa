class Solution {

    void rev(stack<char>&st){


        string temp="";
        while(st.top()!='('){
            temp.push_back(st.top());
            st.pop();
        }

        st.pop();

        for(auto ch:temp){
            st.push(ch);
        }

    }
public:
    string reverseParentheses(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                rev(st);
            }
            else{
                st.push(s[i]);
            }
        }

        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;

    }
};