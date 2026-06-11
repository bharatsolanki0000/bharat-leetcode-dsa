class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){

            int object=asteroids[i];
            //+ve in stack && -ve comes so colision

            if(!st.empty() && object>0){
                st.push(object);
                continue;
            }

            while(!st.empty() && st.top()>0 && st.top()<abs(object)){
                st.pop();
            }

            if(!st.empty() && st.top()>0 && st.top()==abs(object)){
                st.pop();
                continue;
            }

            if(st.empty() || st.top()< 0){
                st.push(object);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};