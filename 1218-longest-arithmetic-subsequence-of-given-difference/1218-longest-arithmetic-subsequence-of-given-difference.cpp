class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int maxi=INT_MIN;
        unordered_map<int,int> dp;
        for(int i=0;i<arr.size();i++){

            int element=arr[i]-difference;
            int tempAns=0;
            if(dp.count(element)){
                tempAns=dp[element];
            }

            dp[arr[i]]=1+tempAns;
            maxi=max(maxi,dp[arr[i]]);
        }

        return maxi;
    }
};