class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          
          int i=0;
          int j=0;
          int ans=0;
          unordered_map<int,int> mp;

          while(j<s.length()){

            while(mp.count(s[j])){
                mp.erase(s[i]);
                i++;
            }
            
            mp[s[j]]++;
            ans=max(ans,(int) mp.size());
            j++;
          }

          return ans;
    }
};