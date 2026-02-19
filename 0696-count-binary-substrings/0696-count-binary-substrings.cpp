class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr=1;
        int prev=0;
        int ans=0;

        int j=1;
        while(j<s.length()){

            if(s[j]==s[j-1]){
                curr++;
            }
            else{
                ans+=min(curr, prev);
                prev=curr;
                curr=1;
            }
            j++;
        }
        ans+=min(curr, prev);
        return ans;
    }
};