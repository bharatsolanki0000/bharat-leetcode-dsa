class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0){
            return false;
        }


        stack<int> st;

        for(int i=0;i<s.length();i++){

            if(st.empty()){
                st.push(s[i]);
                continue;
            }

            int oldElement=st.top();
            int newElement=s[i];

            if((oldElement=='(' && newElement==')') ||
             (oldElement=='[' && newElement==']') ||
             (oldElement=='{' && newElement=='}')){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        return st.empty();

    }
};