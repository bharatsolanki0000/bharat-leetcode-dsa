class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int maxi=0;

        vector<int> temp(128,0);
        while(right<s.length()){

            int elementIndex=s[right];

            if(temp[elementIndex]==1){
                temp[s[left]]=0;
                left++;
                //found duplicate
            }
            else{
                temp[elementIndex]=1;
                right++;
                maxi=max(maxi,right-left);
            }
        }
        return maxi;
    }
};