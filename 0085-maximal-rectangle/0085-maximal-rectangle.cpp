class Solution {

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea=0;

        int size=heights.size();

        for(int i=0;i<=heights.size();i++){


            while(!st.empty()  && ((i==size)|| heights[st.top()]>=heights[i])){

                int height=heights[st.top()];
                st.pop();
                int len;

                if(st.empty()){
                    len=i;
                }
                else{
                    len=i-st.top()-1;
                }

                maxArea=max(maxArea, len*height);
            }
            st.push(i);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int maxi=0;
        vector<int>temp(matrix[0].size(),0);

        for(int i=0;i<matrix.size();i++){

            for(int j=0;j<matrix[0].size();j++){
                  if(matrix[i][j] == '1') {
                    temp[j] += 1;
                    }
                    else {
                        temp[j] = 0;
                    }
            }

            maxi=max(maxi, largestRectangleArea(temp));
        }    
        return maxi;
    }
    
};