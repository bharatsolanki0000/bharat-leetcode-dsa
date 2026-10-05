class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;

        for (auto ch : s) {

            if (ch == '(') {
                st.push(-1);
            }
            else {

                int element = 0;

                // Calculate everything inside current '('
                while (!st.empty() && st.top() != -1) {
                    element += st.top();
                    st.pop();
                }

                // Remove '('
                st.pop();

                // () = 1
                // (A) = 2 * A
                if (element == 0) {
                    st.push(1);
                }
                else {
                    st.push(2 * element);
                }
            }
        }

        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};