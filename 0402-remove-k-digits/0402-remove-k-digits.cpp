class Solution {
public:
    string removeKdigits(string num, int k) {
        

        stack<char>st;
        


        for(int i=0;i<num.length();i++){

            while(!st.empty() && st.top()>num[i] && k){
                st.pop();
                k--;
            }


            st.push(num[i]);

        }

        while(!st.empty() && k>0){
            k--;
            st.pop();
        }

        if(st.empty()){
            return "0";
        }

        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        while( !ans.empty() && ans.back()=='0'){
            ans.pop_back();
        }

        if(ans.empty()){
            return "0";
        }

        reverse(ans.begin(), ans.end());
        return ans;




    }
};