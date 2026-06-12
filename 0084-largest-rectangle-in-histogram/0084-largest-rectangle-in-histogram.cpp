class Solution {

    vector<int> findPrevSmaller(vector<int> &nums){

        vector<int> ans(nums.size());

        stack<int>st;

        for(int i=0;i<nums.size();i++){

            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }

            st.push(i);
        }

        return ans;
    }

     vector<int> findNextSmaller(vector<int> &nums){

        vector<int> ans(nums.size());

        stack<int>st;

        for(int i=nums.size()-1;i>=0;i--){

            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i]=nums.size();
            }
            else{
                ans[i]=st.top();
            }

            st.push(i);
        }

        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> pse=findPrevSmaller(heights);
        vector<int>nse=findNextSmaller(heights);

        int maxiArea=0;

        for(int i=0;i<heights.size();i++){

            int length=nse[i]-pse[i]-1;
            int area=length* heights[i];

            maxiArea=max(maxiArea, area);
            
        }
        return maxiArea;
    }
};