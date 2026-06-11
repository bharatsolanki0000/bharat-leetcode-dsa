class Solution {

    vector<int> findPrevSmaller(vector<int>& nums){

    stack<int> st;
    vector<int> ans(nums.size());

    for(int i=0;i<nums.size();i++){

        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }

    return ans;
}

    vector<int> findNextSmaller(vector<int>& nums){

    stack<int> st;
    vector<int> ans(nums.size());

    int n = nums.size();

    for(int i=n-1;i>=0;i--){

        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }

        ans[i] = st.empty() ? n : st.top();

        st.push(i);
    }

    return ans;
}
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD=1e9+7;
        vector<int> prevSmaller=findPrevSmaller(arr);   
        vector<int> nextSmaller=findNextSmaller(arr);

        int ans=0;
        for(int i=0;i<arr.size();i++){

            int left=i-prevSmaller[i];

            int right=nextSmaller[i]-i;

            long long freq=left*right;
            long long value=(freq*arr[i])%MOD;

            ans=(ans+value)%MOD;
        }

        return ans;
    }
};