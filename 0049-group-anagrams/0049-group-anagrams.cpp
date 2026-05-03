class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;

        for(int i=0;i<strs.size();i++){
            string element=strs[i];
            sort(element.begin(), element.end());
            mp[element].push_back(strs[i]);
            
        }

        vector<vector<string>> ans;

        for(auto word: mp){
            ans.push_back(word.second);
        }

        return ans;
    }
};