class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          
          int i=0;
          int j=0;
          int ans=0;
          vector<int> mp(256);

          

          while(j<s.length()){
               mp[s[j]]++;

            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }

         
            ans=max(ans,j-i+1);
            j++;
          }

          return ans;
    }
};