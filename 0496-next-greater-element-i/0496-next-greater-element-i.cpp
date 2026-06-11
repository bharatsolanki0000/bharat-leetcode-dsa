class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> nextGreater(nums2.size(),-1);

        for(int i=nums2.size()-1;i>=0;i--){

            int first=nums2[i];

            while(!st.empty() && st.top()<first){
                st.pop();
            }

            if(!st.empty()){
                nextGreater[i]=st.top();
            }

            st.push(nums2[i]);
            
        }

        vector<int> ans(nums1.size());
        unordered_map<int,int> mp;
        for(int i=0;i<nextGreater.size();i++){
            mp[nums2[i]]=i;
        }

        for(int i=0;i<nums1.size();i++){

            int index=mp[nums1[i]];
            ans[i]=nextGreater[index];
        }
        return ans;
            
    }
};