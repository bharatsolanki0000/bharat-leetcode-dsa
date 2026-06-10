class Solution {
public:
    bool isValid(string s) {
        

        stack<int> st;

        for(int i=0;i<s.length();i++){

            char first=s[i];

            if(!st.empty()){
                char second=st.top();

                if(second=='(' && first==')'){
                    st.pop();
                }
                else if(second=='[' && first==']'){
                    st.pop();
                }
                else if(second=='{' && first=='}'){
                    st.pop();
                }
                else{
                    st.push(first);
                }
            }
            else{
                st.push(first);
            }
           
            
        }

        return st.empty();
    }
};